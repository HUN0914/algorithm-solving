-- 코드를 입력하세요 limit 3
SELECT ai.NAME, ai.DATETIME from ANIMAL_INS as ai
left join ANIMAL_OUTS as ao
on ai.ANIMAL_ID=ao.ANIMAL_ID
where ao.DATETIME is NULL
order by ai.DATETIME asc
limit 3;