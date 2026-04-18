-- 코드를 작성해주세요

SELECT round(avg(CASE WHEN length is null THEN 10 ELSE length END ),2)as AVERAGE_LENGTH from fish_info;
