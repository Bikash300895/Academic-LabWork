1. Looking at all the tables 
	select * from tab;

2. Creating a table 
	CREATE TABLE stock(
		md_num number(3),
		qty number(3),
		price number(3)
		);

3. Deleting a table
	drop table table_name;

4. Looking at the schema
	desrcibe table_name;

5. Adding new column
	ALTER TABLE TABLE_NAME
		ADD COLUMN_NAME COLUMN_DEFINITION;

6. deleting a column
	ALTER TABLE TABLE_NAME
		DROP COLUMN COLUMN_NAME;

7. Changing data type of a column
	ALTER TABLE specs
		MODIFY tyre number(3);

8. Renaming a column
	ALTER TABLE TABLE_NAME
		RENAME COLUMN old_name to new_name;