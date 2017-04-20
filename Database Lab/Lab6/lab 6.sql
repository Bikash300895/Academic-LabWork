select * from DEPARTMENT;
select * from LOCATION;
SELECT d.dept_id, d.name, l.regional_group
	FROM location l,department d 
	WHERE l.location_id=d.location_id;
SELECT d.dept_id, d.name, l.regional_group
	FROM department d JOIN location l
	ON d.location_id = l.location_id;
SELECT d.dept_id, d.name, l.regional_group
	FROM department d JOIN location l
	USING (location_id);


	SELECT department.location_id, department.name, location.regional_group
	FROM department JOIN location
	USING (location_id);

SELECT d.name, l.regional_group
	FROM department d NATURAL JOIN location l;

SELECT department.name, location.regional_group
	FROM department JOIN location
	ON department.location_id = location.location_id;

SELECT department.name, location.regional_group
	FROM department JOIN location
	USING (location_id);

SELECT * FROM Table DEPARTMENT INNER JOIN LOCATION USING (location_id);

SELECT department.location_id, department.name, location.regional_group
	FROM department NATURAL JOIN location;

	SELECT d.name, l.regional_group
	FROM department d NATURAL JOIN location l;


SELECT location_id, department.name, location.regional_group
	FROM department NATURAL JOIN location;

	select * from supplier;
	select * from part;

	select s.name,p.part_nbr
	from supplier s JOIN part p
	ON s.supplier_id=p.supplier_id;

	SELECT supplier_id, part.part_nbr
	FROM supplier NATURAL JOIN part;

	SELECT s.name, p.part_nbr
	FROM supplier s JOIN part p
	ON s.supplier_id=p.supplier_id;

SELECT supplier.supplier_id, part.part_nbr
	FROM supplier JOIN part
	ON supplier.supplier_id = part.supplier_id
	AND supplier.name = part.name;

	SELECT supplier_id, part.part_nbr
	FROM supplier JOIN part
	USING (supplier_id, name);

	SELECT * FROM employee;
	SELECT * FROM department;

	SELECT e.lname, d.name
	FROM employee e CROSS JOIN department d;

	SELECT e.lname, d.name
	FROM employee e JOIN department d
	ON e.dept_id = d.dept_id;
SELECT e.lname, d.name
	FROM employee e INNER JOIN department d
	ON e.dept_id = d.dept_id;

	SELECT d.dept_id, d.name, l.regional_group
	FROM department d LEFT OUTER JOIN location l
	ON d.location_id = l.location_id;

	SELECT d.dept_id, d.name, l.regional_group
	FROM department d RIGHT OUTER JOIN location l
	ON d.location_id = l.location_id;





SELECT d.dept_id, d.name, l.regional_group
	FROM department d LEFT OUTER JOIN location l
	ON d.location_id = l.location_id;

SELECT d.dept_id, d.name, l.regional_group
	FROM location l RIGHT OUTER JOIN department d
	ON d.location_id = l.location_id;

SELECT d.dept_id, d.name, l.regional_group
	FROM department d FULL OUTER JOIN location l
	ON d.location_id = l.location_id;

	select * from part;
	select * from inventory_class;

SELECT p.name part_name, c.inv_classinv_class
	FROM part p JOIN inventory_class c
	ON p.unit_cost BETWEEN c.low_cost AND c.high_cost;

SELECT p.name , c.inv
	FROM part p,inventory_class c
	ON p.unit_cost BETWEEN c.low_cost AND c.high_cost;

SELECT p.name, c.inv_class
	FROM part p JOIN inventory_class c
	ON p.unit_cost BETWEEN c.low_cost AND c.high_cost;

SELECT p.name as part_name, c.inv_class as i1
	FROM part p JOIN inventory_class c
	ON p.unit_cost BETWEEN c.low_cost AND c.high_cost;
