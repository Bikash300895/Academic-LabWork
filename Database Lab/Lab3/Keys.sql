DROP TABLE course_contents;
1. Setting keys during creating table
CREATE TABLE table_name(
	col1 datatype not null,
	col2 datatype not null,
	PRIMARY KEY (col1),
	FOREIGN KEY (col2) REFERENCES ref_table_name (column_name)
);

2. Setting keys later
alter table table_name add PRIMARY KEY (col_name);
alter table table_name add FOREIGN KEY (col_name) REFERENCES ref_table_name (column_name_in_referance_table)

3. Setting PRIMARY KEY with more than one column
alter table table_name ADD CONSTRAINT constarint_name PRIMARY KEY (col1, col2,..)


4. DROP without naming constraint
ALTER TABLE table_nameDROP UNIQUE KEY;
ALTER TABLEtable_nameDROP PRIMARY KEY;
ALTER TABLEtable_nameDROPFOREIGN KEY;

b.	DROP with naming constraint
ALTER TABLE table_nameDROP CONSTRAINT constraint_name;
