--1
select min(basic) , max(basic), avg(basic) from emp group by dept_code;

--2
select count(*) as No_of_females, dept_code from emp where sex='F' group by dept_code;

--3

