slow=head;
fast=head;

//slow is for 1 position ahead
//fast for two position ahead
while(slow!=NULL)
{
	slow=slow->next;
	fast=fast->next->next;

	if(slow==fast)
		loop
	

}