
-- Created by Nelson Mitchell ©2017

-- set up the db
create database scores;
use scores;
drop table highscores;
-- we only need one simple table, primary hidden key id auto-increments so same user can have multiple highscores
create table highscores (id int not null AUTO_INCREMENT, user VARCHAR(6), score int, PRIMARY KEY (id));

-- some dummy data to populate
insert into highscores (user, score) values ("nelson", 100000),
                                            ("samuel", 1000000),
                                            ("theo",10000000),
                                            ("mahalia", 10000000),
                                            ("jordan", 100000000);

-- display the highscores in order of highest score so we know it worked
select user, score from highscores order by score desc;

-- clean up
drop procedure add_score;
drop procedure getScores;

-- switch the delimiter for multiple-line procedures
delimiter //

-- insert user score
CREATE PROCEDURE add_score(IN in_user VARCHAR(6), IN in_score int)
  BEGIN
  insert into highscores (user, score)
    values (in_user, in_score);
  END//

-- get scores back as result set
CREATE PROCEDURE getScores()
    BEGIN
    select user, score from highscores
      order by score desc
      limit 10;
    END//

delimiter ;
