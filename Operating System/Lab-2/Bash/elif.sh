echo "choose option from 1 to 3"
read choice

if [ $choice -eq 1 ]
then
	date
elif [ $choice -eq 2]
then 
	hostname
elif [ $choice -eq 3 ]
then
	cal
else
	echo "Invalid coice! \07\07"
fi
