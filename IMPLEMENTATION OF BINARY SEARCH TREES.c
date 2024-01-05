#include<stdio.h>
int main()
{
int c, first, last, middle, n, search, array[100];
printf(&quot;Enter number of elements:\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter %d integers:\n&quot;, n);
for (c = 0; c &lt; n; c++)
scanf(&quot;%d&quot;,&amp;array[c]);
printf(&quot;Enter the value to find:\n&quot;);
scanf(&quot;%d&quot;, &amp;search);
first = 0;
last = n - 1;
middle = (first+last)/2;
while (first &lt;= last) {

if (array[middle] &lt; search)
first = middle + 1;
else if (array[middle] == search) {
printf(&quot;%d is present at index %d.\n&quot;, search, middle+1);
break;
}
else
last = middle - 1;
middle = (first + last)/2;
}
if (first &gt; last)
printf(&quot;Not found! %d is not present in the list.\n&quot;, search);
return 0;
getch();
}
