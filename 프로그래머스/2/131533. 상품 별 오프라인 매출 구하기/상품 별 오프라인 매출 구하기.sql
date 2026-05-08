-- 코드를 입력하세요
SELECT pr.PRODUCT_CODE, sum(pr.PRICE*os.SALES_AMOUNT) as SALES from PRODUCT as pr
join OFFLINE_SALE as os 
on pr.PRODUCT_ID=os.PRODUCT_ID
group by PRODUCT_CODE
order by SALES desc, PRODUCT_CODE asc;