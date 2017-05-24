0. Looking at all the tables 
	select * from tab;
	
Creating users
CREATE USER books_admin IDENTIFIED BY MyPassword;

	GRANT CONNECT TO books_admin;
	In some cases to create a more powerful user, you may also consider adding the RESOURCE role (allowing the user to create named types for custom schemas) or even the DBA role, which allows the user to not only create custom named types but alter and destroy them as well.

	GRANT CONNECT, RESOURCE, DBA TO books_admin;

1. CREATE TABLE users(
  id int NOT NULL AUTO_INCREMENT,
  username varchar(50) NOT NULL,
  password varchar(50) NOT NULL,
  first_name varchar(50) NOT NULL,
  last_name varchar(50) NOT NULL,
  PRIMARY KEY (id)
  )


	CREATE TABLE stock(
		md_num number(3),
		qty number(3),
		price number(3)
		);


2. Setting key constrain
	CREATE TABLE table_name(
		column_name1	datatype 	NOT NULL,
		column_name2	datatype,
		……………………………….
		column_namen	datatype,
		PRIMARY KEY (column_name1),
		FOREIGN KEY (column_name2) REFERENCES reference_table_name
	);

	create table course_taken(
		roll 	number(7) 	not null,
		c_id 	number(10) not null,
		sess	varchar(10) not null,
		FOREIGN KEY (roll) REFERENCES students(roll) on delete cascade 
	);


	a.	Create a PRIMARY KEY constraint on a column when the table is already created
			ALTER TABLE table_name ADD UNIQUE KEY (column_name1);
			ALTER TABLE table_name ADD PRIMARY KEY (column_name1);
			ALTER TABLE table_name ADD FOREIGN KEY (column_name1) REFERENCES reference_table_name 	(column_name_in_reference_table);


	



3. Deleting a table
	drop table table_name;

4. Looking at the schema
	desrcibe table_name;

5. Adding new column
	ALTER TABLE TABLE_NAME
		ADD COLUMN_NAME COLUMN_DEFINITION;

	ALTER TABLE TABLE_NAME
	ADD (	COLUMN_NAME1	COLUMN_DEFINITION1,
		COLUMN_NAME2	COLUMN_DEFINITION 2,
		…………………………………………………….,
		COLUMN_NAMEn	COLUMN_DEFINITIONn);


6. deleting a column
	ALTER TABLE TABLE_NAME
		DROP COLUMN COLUMN_NAME;

7. Changing data type of a column

	ALTER TABLE TABLE_NAME 
	MODIFY COLUMN_NAME COLUMN_DEFINITION;

	ALTER TABLE specs
		MODIFY tyre number(3);

8. Renaming a column
	ALTER TABLE TABLE_NAME
		RENAME COLUMN old_name to new_name;



-- Inserting deleting and update
1. Inserting
	insert into student values(1407001, 'bikash', 3.27);

2. Updating
	UPDATE table_name
	SET column_name=corrected_value
	< WHERE criteria_to_find_desired_place_in_that_column >;

	UPDATE cars SET year=2007 WHERE md_name=’Ford’;


3. Deleting
	DELETE FROM table_name
	WHERE criteria_to_delete_item;

	DELETE FROM cars WHERE md_name=’Ford’;

