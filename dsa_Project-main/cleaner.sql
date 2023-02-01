use University;





CREATE TEMPORARY TABLE del3

select distinct country from t20 order by country limit 1;



update t20 set country  = "not found" where country = (select * from del3);
update t20 set name  = trim(name) where name is not null;



-- select * from t20 where name = "Ziaur Rahman";
-- select distinct country from t20 order by country limit 1;




-- select count(*) from t20 as t where country not in (select distinct t1.country from t20 as t1);
-- select count(name) from t20;


-- select  country from t20 order by country;-- 