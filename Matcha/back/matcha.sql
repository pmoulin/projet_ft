DROP DATABASE IF EXISTS matcha;
CREATE DATABASE matcha;

\c matcha;

CREATE TABLE users
(
  ID SERIAL PRIMARY KEY,
  login VARCHAR,
  pwd VARCHAR,
  email VARCHAR,
  age INTEGER,
  active BOOLEAN DEFAULT FALSE
);

INSERT INTO users
  (login, pwd, email, age, active)
VALUES
  ('testLogin', 'testPassword', 'testemail@email.com', 3, TRUE);

INSERT INTO users
  (login, pwd, email, age)
VALUES
  ('testLogin1', 'testPassword1', 'testemail1@email.com', 10);