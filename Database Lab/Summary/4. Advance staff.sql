1. Write a SQL query to find all the details of 1970 winners by the ordered to subject and winner name; but the list contain the subject Economics and Chemistry at last.
==> 
SELECT *  
FROM nobel_win  
WHERE year=1970   
ORDER BY  
 CASE  
    WHEN subject IN ('Economics','Chemistry') THEN 1  
    ELSE 0  
 END ASC,  
 subject,  
 winner;  

 http://www.w3resource.com/sql-exercises/sql-retrieve-exercise-24.php




2. Write a SQL query to find the name and price of the cheapest item.
==>
SELECT pro_name, pro_price  
   FROM item_mast  
   WHERE pro_price =   
    (SELECT MIN(pro_price) FROM item_mast);  