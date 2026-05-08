-- 코드를 입력하세요
SELECT distinct c.CAR_ID as CAR_ID from CAR_RENTAL_COMPANY_CAR as c
join CAR_RENTAL_COMPANY_RENTAL_HISTORY as his
on c.CAR_ID=his.CAR_ID
where c.CAR_TYPE='세단' and his.START_DATE>='2022-10-01'
order by CAR_ID desc;