Here customers is a table ** 
it has column name, state, zip etc

Showing tha data base names
SHOW DATABASES

selecting all from database
SELECT * FROM customers 

secelting a specific column in a table
SELECT state FROM customers

secelcting only the distinct (non repeating) elements
SELECT DISTINCT state from customers

Limiting the number of results
SELECT DISTINCT state from customers LIMIT 5

Limit with range
SELECT DISTINCT state from customers LIMIT 5,10 (show elemnts from 6 to 15)

fully qualified name
SELECT customers.state FROM customers

Sorting
SELECT name FROM customers ORDER BY name
SELECT name,address FROM customers ORDER BY id (id is other property)
SELECT name,address,id FROM customers ORDER BY state, name

*Reverse Sorting
SELECT name FROM customers ORDER BY name DESC

Selecting specification
SELECT id, name FROM customers WHERE id=54 (or < or > or != or any other)
SELECT id, name FROM customers WHERE id BETWEEN 25 AND 30
SELECT state FROM cuntomers WHERE state = 'CA'
SELECT state FROM cuntomers WHERE state = 'CA'ANd city='Hollywood'
SELECT state FROM cuntomers WHERE state = 'CA'OR city='Hollywood'
SELECT state FROM cuntomers WHERE (id=1 OR id=2) ANd state = 'CA'
SELECT * FROM person WHERE Left(name,1)='b'

Avoiding many OR we can use IN
SELECT name,state FROM cuntomers WHERE state IN('NY','NC','CA')
SELECT name,state FROM cuntomers WHERE state NOT IN('NY','NC','CA')

Like Statement
SELECT name FROM items WHERE name LIKE 'new%' (All the names that starts with the word 'new' , We can also use '%new' what ends with word 'new' or '%new%' that has new inside any word )
SELECT name FROM items WHERE name LIKE 'h%d'
SELECT name FROM items WHERE name LIKE '_ boxes of grogs' (here '_' means only one character, so it can be '5 boxes of frog' but not '57 boxes of frog' )

Regular Expression
SELECT name FROM items WHERE name REGEXP 'new' (REGEXP stands for regular expression, it menans find all with the word new whether it is part of other word or inside or left or right anything)
SELECT name FROM items WHERE name REGEXP '.new' (stands for single charecter, not quite sure :/ )
SELECT name FROM items WHERE name REGEXP 'new|car' (search for new or car)
SELECT name FROM items WHERE name REGEXP '[12345] boxes of frogs' (search for 1 or 2 or ... boxes for frogs)
SELECT name FROM items WHERE name REGEXP '[1-5] boxes of frogs' (search for 1 or 2 or ... boxes for frogs)
SELECT name FROM items WHERE name REGEXP '[^12345] boxes of frogs' (search for except 1 or 2 or ... boxes for frogs)

Concat
SELECT CONCAT(city, ', ', state) FROM customers (ex, hellywood, CA) here CONCAT(city, ', ', state) is a custom column
SELECT CONCAT(city, ', ', state) AS new_arrdess FROM customers new_address will be the name of column

Custom column (more)
SELECT name. cost, cost-1 AS sell_price FROM items (here cost-1 is a new column as sell_price

Function
SELECT name, UPPER(name) FROM customers
SELECT cost, SQRT(cost) FROM items
SELECT AVG(cost) FROM items
SELECT SUM(bids) FROM items
SELECT COUNT(name) FROM items WHERE seller_id=6
SELECT AVG(cost) FROM items WHERE seller_id=6

SELECT COUNT(*) AS item_count,
MAX(cost) AS max,
AVG(cost) AS avg
FROM items WHERE seller_id=12

Group By
SELECT seller_id, COUNT() AS item_count FROM items WHERE seller_id=1 (it will show the count of items with seller id=1, we can list all by following way)
SELECT seller_id, COUNT() AS item_count FROM items GROUP BY seller_id
SELECT seller_id, COUNT() AS item_count FROM items GROUP BY seller_id HAVING COUNT()>=3 ORDER BY item_count DESC

Sub Query
SELECT name, cost FROM items WHERE cost>(
SELECT AVG(cost) FROM items
) ORDER BY cost DESC 

SELECT name, MIN(cost) FROM itmes WHERE name LIKE '%boxes of frogs' AND seller_id IN (
SELECT seller-id FROM items WHERE name like '%boxes of frogs'
)

Joining Tables
SELECT customers.id, customers.name, items,name, items.cost
FROM customrs,items
WHERE customers.id = seller.id
ORDER BY customers.id

LEFT and RIGHT OUTER
SELECT customers.name, items,name
FROM customrs LEFT OUTER JOIN items
ON customers.id = seller.id
ORDER BY customers.id (this includes all items of items)

SELECT customers.name, items,name
FROM customrs RIGHT OUTER JOIN items
ON customers.id = seller.id
ORDER BY customers.id (this includes all items of customers)

UNION
SELECT name, sot bids FROM items WHERE bids>190
UNION 
SELECT name, cost, bids FROM items WHERE cost>1000 (This combines both results and removes duplicate naturally)
SELECT name, sot bids FROM items WHERE bids>190
UNION ALL
SELECT name, cost, bids FROM items WHERE cost>1000 (This combines both results and does not removes duplicate naturally)

MATCH and AGAINST
SELECT name, cost FROM items WHERE MATCH(name) AGAINST('baby') (Search for word 'baby')
SELECT name, cost FROM items WHERE MATCH(name) AGAINST('+baby -cost') (Search for word 'baby' and dont have the word 'cost')

Insertin into a table
INSERT INTO items VALUES('101,'bacon strips', '9.95', '1', '0')
INSERT INTO items(id,name,cost,seller_id,bids) VALUES('101,'bacon strips', '9.95', '1', '0')

Updating a item
UPDATE items SET name='cake' WHERE id='106'
UPDATE items SET name='cake' cost=10.99 WHERE id='106'

Deleting
DELETE FROM items WHERE id = 106

Creating a new table
CREATE TABLE users(
id int,
userName varchar(30),
password varchar(20)
)

//We can set one item as primary key
CREATE TABLE users(
id int,
userName varchar(30),
password varchar(20),
PRIMARY KEY(id)
)

//Any item can set as not null, means it can be left blank during insertion and set some item as auto increasing
CREATE TABLE users(
id int NOT NULL AUTO_INCREMENT,
userName varchar(30) NOT NULL,
password varchar(20) NOT NULL,
PRIMARY KEY(id)
)

Adding a new column
ALTER TABLE bacon ADD sampleColumn varchar(10)

Deleting an entire table
DROP TABLE bacon

Deleting a column
ALTER TABLE bacon DROP COLUMN samplecolumn

Renaming a table
Rename TABLE customres TO users

Creating a view (temporaray table)
CREATE VIEW mostbids AS
SELECT id, name, bids FROM items ORDER BY bids DESC LIMIT 10
