-- 코드를 입력하세요
SELECT b.book_id,a.author_name,b.published_date from book as b natural join author as a
where b.category = "경제"
order by b.published_date asc ;