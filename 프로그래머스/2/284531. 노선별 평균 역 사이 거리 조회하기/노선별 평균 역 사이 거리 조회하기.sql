SELECT 
    route AS "ROUTE",
    CONCAT(round(SUM(d_between_dist), 1), 'km') AS "TOTAL_DISTANCE", 
    CONCAT(round(AVG(d_between_dist), 2), 'km') AS "AVERAGE_DISTANCE" 
FROM subway_distance
GROUP BY route
/* 별칭인 "TOTAL_DISTANCE"가 아니라, 실제 숫자 합계 함수를 정렬 기준에 넣으세요 */
ORDER BY SUM(d_between_dist) DESC;