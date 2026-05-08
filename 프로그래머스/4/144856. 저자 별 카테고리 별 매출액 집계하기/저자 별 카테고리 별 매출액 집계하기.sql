-- 카테고리별 매출액 (판매량 * 판매가) 판매량은 BOOK_SALES의 SALES
SELECT b.AUTHOR_ID as AUTHOR_ID, a.AUTHOR_NAME as AUTHOR_NAME, b.CATEGORY as CATEGORY, sum(bs.SALES*b.PRICE) as TOTAL_SALES from book b
join BOOK_SALES as bs
on b.BOOK_ID=bs.BOOK_ID
join AUTHOR as a
on b.AUTHOR_ID=a.AUTHOR_ID

where bs.SALES_DATE between '2022-01-01' and '2022-01-31'
group by category, AUTHOR_ID, CATEGORY
order by AUTHOR_ID asc, b.CATEGORY desc;