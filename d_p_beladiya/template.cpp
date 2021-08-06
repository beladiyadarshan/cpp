static async getHomeInternetGraphDetails(params) {
    const { filters, lastUpdatedDate, months, trendMonth } = params;
    let { pastMonths } = params;

    const homeInternetDf = await DailyStatementService.getHomeInternetDf(filters);

    const monthDataGroup = homeInternetDf.groupby(['month_year']);

    const hasTrendMonthData = Object.keys(monthDataGroup.col_dict).includes(
      trendMonth[0]
    );

    const pastMonthsDataColumns = [
      'home_sales_rate',
      'total_sales',
      'home_sales',
    ];
    pastMonths = pastMonths.filter((pastMonth) =>
      Object.keys(monthDataGroup.col_dict).includes(pastMonth)
    );
    let trendAndPastMonthsData = this.getTrendAndPastMonthsData({
      monthDataGroup,
      trendMonth,
      pastMonths,
      pastMonthsDataColumns,
      filters,
    });

    if (hasTrendMonthData) {
      const trendingDate = utils.getTrendingValueDate({
        filterMonth: trendMonth[0],
        lastUpdatedDate,
      });

      const { daysInMonth, day } = trendingDate;

      const linerTrend = this.getLinearTrend({
        monthData: trendAndPastMonthsData,
        pastMonths,
        targetAchievementColumn: 'home_sales_rate',
        targetAchievementTrendingColumn: 'home_sales_rate',
      });

      trendAndPastMonthsData = this.addLinearTrend({
        monthData: trendAndPastMonthsData,
        linerTrend,
      });
    } else {
      trendAndPastMonthsData.addColumn({
        column: 'is_linear_trend',
        value: Array(trendAndPastMonthsData.shape[0]).fill(-1),
      });
    }

    trendAndPastMonthsData = danfoUtils.addEmptyColumn(
      trendAndPastMonthsData,
      ['level'],
      filters.level
    );

    if (filters.level && filters.level === 'employee') {
      trendAndPastMonthsData = await this.addEmployeeDetails(
        trendAndPastMonthsData,
        filters
      );
    }

    const result = await trendAndPastMonthsData.to_json();
    return {
      data: JSON.parse(result),
    };
  }