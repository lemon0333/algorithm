-- 코드를 작성해주세요
select count(*) as fish_count from fish_info inner join fish_name_info on fish_name_info.fish_type = fish_info.fish_type
where fish_name_info.fish_name in ('BASS', 'SNAPPER');