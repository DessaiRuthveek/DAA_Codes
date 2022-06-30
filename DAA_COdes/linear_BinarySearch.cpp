#include &lt;stdio.h&gt;
int L_Search(int length, int x, int arr[])
{
 int i, pass = 0;
for (i = 0; i&lt;length; i++)
 {
pass++;
 if(arr[i] == x)
{




printf(&quot;\nSearch Completed with %d passes.\n&quot;, pass);
 return i;
}
 }
 return 0;
}
int I_B_Search(int arr[], int l, int r, int x)
{
 int pass=0;
 while (l &lt;= r) {
 int i = l + (r - l) / 2;

 if (arr[i] == x)
 {
 printf(&quot;\nSearch Completed with %d passes.\n&quot;, pass);
return i;
 }

 if (arr[i] &lt; x)
{
 l = i + 1;
 pass++;
 }
else
{
r = i - 1;
 pass++;
 }
 }
return 0;
}
int B_Search(int arr[], int l, int r, int x)
{
int pass=0;
if(r&gt;=1)
{
 int mid = (l + (r-1))/2;
if (arr[mid] == x)
 {
printf(&quot;\nSearch Completed with %d passes.\n&quot;, pass);
return mid;
 }
 if (x &lt; arr[mid])
 {
return B_Search(arr, l, mid-1, x);
 pass++;
 }
if(x &gt; arr[mid])
 {
 return B_Search(arr, mid+1, r, x);
 pass++;



}
 }
 return 0;
}
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i &lt; n; i++) {
 key = arr[i];
j = i - 1;
while (j &gt;= 0 &amp;&amp; arr[j] &gt; key)
 {
 arr[j + 1] = arr[j];
j = j - 1;
 }
 arr[j + 1] = key;
}
printf(&quot;Array After Sort: \n&quot;);
for(i = 0; i&lt;n; i++)
{
 printf(&quot;%d &quot;, arr[i]);
 }
}
void takeInput(int arr[],int n){
 for(int i=0;i&lt;n;i++){
printf(&quot;Enter element %d : &quot;,i+1);
scanf(&quot;%d&quot;,&amp;arr[i]);
}
}
int main()
{
 char ch;
 int x, arr[15], n, cho, index,num;
 do{
 index;
 printf(&quot;Enter Total Number Of Elements In Array : &quot;);
 scanf(&quot;%d&quot;, &amp;n);
takeInput(arr,n);
 insertionSort(arr, n);
printf(&quot;\nEnter element to be searched for : &quot;);
scanf(&quot;%d&quot;, &amp;x);
 printf(&quot;1. Linear Search.&quot;);
printf(&quot;\n2. Recursive Binary Search.&quot;);
printf(&quot;\n3. Iterative Binary Search.&quot;);
printf(&quot;\nEnter your choice : &quot;);
scanf(&quot;%d&quot;, &amp;cho);
 switch(cho)
 {
 case 1:
index = L_Search(n,x,arr);
break;
case 2:

index = B_Search(arr, 0, n-1, x);
 break;
case 3:
index = I_B_Search(arr, 0, n-1, x);
 break;
default:
 printf(&quot;Invalid choice..&quot;);
 }

 if (index != 0)
printf(&quot;Element was found in entered array at index %d\n&quot;, index);
 else
 printf(&quot;Element was not found in entered array.\n&quot;);

printf(&quot;\nDo you want to run the program again? (y/Y) : &quot;);
scanf(&quot; %c&quot;, &amp;ch);
}while (ch ==&#39;y&#39;|| ch ==&#39;Y&#39;);


 return 1;
}