# it's pure bellmanford algorithmic question
# well asked


import itertools

def solution(times, time_limit):
  buns = len(times) - 1
  ibuns = [bunny  for bunny in range(1,buns)]

  disMat = doBellmanFord(times)
  if isNegative(disMat):
    return range(buns-1)

  for width in range(buns-1, 0, -1):
    for perm in itertools.permutations(ibuns, width):
      cost = getCost(perm, disMat)
      if cost <= time_limit:
        x= [bunny for bunny in sorted(perm)]
        for i in range(len(x)):
            x[i]-=1
        return x;
  
  return []


def doBellmanFord(edges):
  disMat = []
  for vertex in range( len(edges) ):
    distances = bellmanFord(edges, vertex)
    disMat.append(distances)
  return disMat


def bellmanFord(edges, start):
  distances = [ float('inf') for vertex in edges ]
  distances[start] = edges[start][start]
  for i in range(len(edges)):
    for u, v, weight in enumerateEdges(edges):
        x = distances[u] + weight ;
        
        if x < distances[v]:
            distances[v] =x  
  return distances
    
def enumerateEdges(edges):
  for u, row in enumerate(edges):
    for v, weight in enumerate(row):
      yield (u, v, weight)

def isNegative(mat):
  distances = mat[0]
  for u, v, weight in enumerateEdges(mat):
    if distances[u] + weight < distances[v]:
      return True
  return False


def getCost( bunnies, disMat ):
  cost = 0
  for i in range(0, len(bunnies) - 1):
      cost += disMat[bunnies[i]][bunnies[i+1]]
  sNode = 0
  eNode = len(disMat) - 1
  cost += disMat[sNode][bunnies[0]]
  cost += disMat[bunnies[-1]][eNode]
  return cost





    cin>>t;
    while(t--){
        cin>>x;
        S=0;
        z=1;
        while((3*z*z+z)/2<x){
            z++;
        }
        while(x>1){
            while((3*z*z+z)/2>x){
                z--;
            }
            x-=(3*z*z+z)/2;
            S++;
        }
        cout<<S<<endl;
    }
  