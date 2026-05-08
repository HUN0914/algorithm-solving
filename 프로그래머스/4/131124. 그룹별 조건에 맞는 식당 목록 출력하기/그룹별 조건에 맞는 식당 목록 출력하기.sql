-- 리뷰 가자ㅓㅇ 많이 작성한 회원들의 리뷰 조회하는 sql문
-- count(member_id) 기준으로 내림차순 해서 ㅏ가장 많이 쓴 member를 구하고
-- 그 멤버 기준으로 정보 주되 작성일 기준 오름차순, 텍스트 기준 오름차순
SELECT mp.MEMBER_NAME, rr.REVIEW_TEXT, rr.REVIEW_DATE from REST_REVIEW rr

inner join MEMBER_PROFILE mp

on mp.MEMBER_ID=rr.MEMBER_ID

where rr.MEMBER_ID = (
    select MEMBER_ID
    from REST_REVIEW
    group by MEMBER_ID 
    order by count(*) desc
    limit 1
)

order by rr.REVIEW_DATE asc, rr.REVIEW_TEXT asc;