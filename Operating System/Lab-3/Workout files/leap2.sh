echo "enter e year number: "
read year

if [ $((year%4)) -eq 0 ] && [ $((year%100)) -eq 0 ] && [ $((year%400)) -ne 0 ]
then 
	echo "leap year"

else
	echo "not a leap year"
fi
