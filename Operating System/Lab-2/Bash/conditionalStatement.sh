echo "Would you like to see a joke (y/n)?"
read reply

if [ "$reply" = "y" ]
then 
	echo "thank you. here we go..."
else 
	echo "don't have the mode. ok, see u another day"
fi
	echo "have a nice day"

 

# Complex conditional satement

echo "1. show date"
echo "2. Show hostname"
echo "3. Show current working directory"
echo "4. please select the choice between (1,2,3)"

read menunumber

if [ $menunumber -eq 1 ]
	then
		date
	else if [ $menunumber -eq 2 ]
		then 
			hostname
		else if [ $menunumber -eq 3 ]
			then
				pwd
			else "Invalid choice! \07\07"
			fi
		fi
	fi
	echo "\nThank you for using UNIX Shit"

