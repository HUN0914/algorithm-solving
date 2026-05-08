select year(e.DIFFERENTIATION_DATE) as YEAR, (p.SIZE_OF_COLONY- e.SIZE_OF_COLONY) as YEAR_DEV, e.ID as ID from ECOLI_DATA e

join (

    select year(DIFFERENTIATION_DATE) as YEAR, max(SIZE_OF_COLONY) as SIZE_OF_COLONY
    from ECOLI_DATA
    group by YEAR
) p

ON p.YEAR = YEAR(e.DIFFERENTIATION_DATE)

order by YEAR asc, YEAR_DEV asc;