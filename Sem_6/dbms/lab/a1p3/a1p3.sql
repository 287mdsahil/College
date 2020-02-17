--1
create table emp(
	emp_code char(5) primary key, 
	emp_name char(20), 
	dept_code char(5), 
	desig_code char(5), 
	sex char(1), 
	address char(25), 
	city char(20), 
	state char(20), 
	pin char(6), 
	basic numeric, 
	jn_dt date
);

create table designation(
	desig_code char(5) primary key,
	desig_desc char(20)
);

create table department(
	dept_code char(5) primary key,
	dept_name char(15)
);

--2
desc emp;
desc designation;
desc department;

--3
insert into designation values('mgr','manager');
insert into designation values('EXEC','Executive');
insert into designation values('OFR','Officer');
insert into designation values('CLK','Clerk');
insert into designation values('HLPR','Helper');

insert into department values('PER','Personnel');
insert into department values('PROD','Production');
insert into department values('PRCH','Purchase');
insert into department values('FNC','Finance');
insert into department values('RSH','Research');

--4
insert into emp values('00000', 'SAHIL', 'RSH', 'MGR', 'M', 'Islampur', 'Dubrajpur', 'WB', '731123', 100000, '2017-07-01');
insert into emp values('00001', 'BIKRAM', 'RSH', 'EXEC', 'M', 'Benachiti', 'Durgapur', 'WB', '770433', 50000, '2017-07-01');
insert into emp values('00002', 'Irin', 'FNC', 'EXEC', 'F', 'Jadavpur', 'Kolkata', 'WB', '700032', 150000, '2018-07-01');
insert into emp values('00003', 'Anindya', 'PROD', 'HLPR', 'M', 'Benachiti', 'Durgapur', 'WB', '100433', 50000, '2017-01-23');
insert into emp values('00004', 'Tommy', 'FNC', 'EXEC', 'M', 'Baruipur', 'Kolkata', 'WB', '745500', 50000, '2018-06-23');
insert into emp values('00005', 'Sadrul', 'RSH', 'EXEC', 'M', 'GOlapbag', 'Burdwan', 'WB', '700032', 50000, '2016-04-03');
insert into emp values('00006', 'Devesh', null, 'OFR', 'M', 'A-zone', 'Rachi', 'Bihar', '123456', null, '2018-03-04');
insert into emp values('00007', 'Priyank', null, 'CLK', 'M', 'B-zone', 'Rachi', 'Bihar', '123456', null, '2018-02-01');
insert into emp values('00008', 'Sajjad', 'PER', 'CLK', 'M', 'Park Circus', 'Kolkata', 'WB', '700034', 0, '2018-02-01');

--5
select * from emp where dept_code is null;

--6
select * from emp where basic = 0;

--7
select * from emp where basic is null;

--8
select avg(basic) from emp;

--9
update emp set basic=0 where basic is null;

--10
select avg(basic) from emp;

--11
delete from emp where dept_code is null;

--12
select emp_name, basic+0.5*basic+0.4*basic net_pay from emp;

--13
select upper(emp_name), basic, dept_code from emp order by dept_code;

--14
select * from emp where jn_dt>'1990-01-01';

--15
select count(*) from emp where substr(jn_dt,6,2)='01';

--16
select max(basic), min(basic) from emp;

--17
select count(*) from emp where sex='F';

--18
update emp set city=upper(city);

--19
select count(distinct city) from emp;

--20
select * from emp order by dept_code, basic desc;
