-- 집계함수 컬럼, 일반 컬럼 같이 쓰려 하면 무조건 그룹 바이 써줘야함. 
SELECT fp.PRODUCT_ID, fp.PRODUCT_NAME, sum(fo.AMOUNT * fp.PRICE) as TOTAL_SALES
from FOOD_PRODUCT fp 

inner join FOOD_ORDER fo on fp.PRODUCT_ID=fo.PRODUCT_ID

where fo.PRODUCE_DATE between '2022-05-01' and '2022-05-31'

group by fp.PRODUCT_ID

order by TOTAL_SALES desc, fp.PRODUCT_ID asc;
