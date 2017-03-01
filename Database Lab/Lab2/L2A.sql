drop table stock;
drop table specs;
drop table cars;

create table cars(
	md_num	integer,
	md_name	varchar(10),
	style	varchar(10),
	year	integer
);

create table specs(
	md_num	integer,
	mpg	integer,
	radio	varchar(10),
	engine	varchar(10)
);

create table stock(
	md_num	integer,
	qty	integer,
	price	integer
);