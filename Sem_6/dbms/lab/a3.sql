--1
create table department(
	dept_code char(5) primary key,
	name char(20)
);

create table employee(
	emp_code char(5) primary key,
	dept_code char(5),
	name char(20) check(binary name=upper(name)),
	address char(20),
	basic numeric check(basic>=5000 and basic<=9000),
	jn_date date default CURRENT_TIMESTAMP,
	foreign key (dept_code) references department(dept_code)
);


create table leaves(
	emp_code char(5),
	type enum('CL','EL','ML'),
	from_date date,
	to_date date,
	foreign key (emp_code) references employee(emp_code)
);


insert into department values("SYS","Systems");
insert into department values("FIN","Finance");
insert into department values("HR","Human Resources");

insert into employee values('sah01','SYS','SAHIL','Dubrajpur',6000,default);
insert into employee values('bik02','FIN','BIKRAM','Durgapur',8000,default);

insert into leaves values("bik02", "CL", "2020-09-27", "2020-10-20");


--3a
create table emp2 select emp_code, name, dept_code, basic from employee where basic=6000 and dept_code='SYS';

--3b
insert into emp2 select emp_code, name, dept_code, basic from employee where basic>=7000;

--3c
 alter table emp2 add net_pay numeric;

--3d
 update emp2 set net_pay=1.5*basic;

--3e
 alter table emp2 drop net_pay;

--4
drop table emp2;
drop table leaves;
drop table employee;
drop table department;

