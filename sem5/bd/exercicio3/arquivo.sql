-- EXERCICIO 3 - SQL
-- Maria Eduarda Kawakami Moreira - 11218751

-------------------- Q1 --------------------
-- Selecionar o nome e o estado dos times que possuem uniforme titular mas a
-- cor principal não foi cadastrada.
SELECT T.nome, T.estado
FROM Time T 
INNER JOIN Uniforme U
    ON T.nome = U.time
WHERE U.tipo = 'TITULAR' AND U.cor_principal is null;

-- Para os casos de teste, vamos adicionar mais três uniformes:
-- 1) Uniforme titular da chapecoense com cor principal null
-- 2) Uniforme titular do botafogo com cor principal branco.
-- 3) Uniforme reserva do cruzeiro com cor principal null
-- O resultado esperado então é que apenas o 1 apareça dentre os adicionados.
INSERT INTO UNIFORME (TIME, TIPO, COR_PRINCIPAL) VALUES ('CHAPECOENSE', 'TITULAR', NULL);
INSERT INTO UNIFORME (TIME, TIPO, COR_PRINCIPAL) VALUES ('BOTAFOGO', 'TITULAR', 'VERMELHO'); 
INSERT INTO UNIFORME (TIME, TIPO, COR_PRINCIPAL) VALUES ('CRUZEIRO', 'RESERVA', NULL); 

-------------------- Q2 --------------------
-- Selecionar, para cada jogador: nome, data de nascimento, time em que joga,
-- estado do time e, se o time jogou alguma partida clássica, listar também
-- data e local da partida.
SELECT J.nome, J.data_nasc, J.time, T.estado, ultimo.data, P.local
FROM Jogador J
INNER JOIN Time T
	ON J.time = T.nome
-- Caso não haja uma partida classica relacionada com o time, o left join
-- garante que data e local da partida serão null e que eles serão incluídos.
LEFT JOIN (
	-- Seleciona todos os times que jogaram partidas clássicas
	-- e a data do último jogo.
	SELECT T.nome, MAX(P.data) AS data
	FROM Time T
	INNER JOIN Partida P
		ON T.nome = P.time1 OR T.nome = P.time2
	INNER JOIN Joga J
		ON J.time1 = P.time1 AND J.time2 = P.time2
	WHERE J.classico = 'S'
	GROUP BY T.nome
) ultimo
	ON T.nome = ultimo.nome
-- Left Join para conseguir também os times que não jogaram 
-- uma partida clássica.
LEFT JOIN Partida P
	ON (P.time1 = T.nome OR P.time2 = T.nome) AND P.data = ultimo.data;

-- Apenas com os dados já inseridos, já é possível verificar bem a query.


-------------------- Q3 --------------------
-- Selecionar a quantidade de partidas de jogos clássicos 
-- e de jogos não clássicos ocorridos em períodos de férias
-- de verão (meses de janeiro e fevereiro).
SELECT J.classico, COUNT(*)
FROM Joga J
INNER JOIN Partida P
	ON J.time1 = P.time1 AND J.time2 = P.time2
WHERE EXTRACT(MONTH FROM P.data) BETWEEN 1 AND 2
GROUP BY J.classico;

-- Para os casos de teste, vamos inserir mais tuplas em joga e mais partidas
-- que ocorrem nos meses de janeiro e fevereiro.
INSERT INTO JOGA (TIME1, TIME2, CLASSICO) VALUES ('ATLETICO', 'CRUZEIRO', 'N');
INSERT INTO JOGA (TIME1, TIME2, CLASSICO) VALUES ('BOTAFOGO', 'FLAMENGO', 'N');
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('ATLETICO', 'CRUZEIRO', TO_DATE('2017/02/01 16:00:00', 'YYYY/MM/DD HH24:MI:SS'), '4X2', 'GUARATINGUETA');
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('BOTAFOGO', 'FLAMENGO', TO_DATE('2020/01/25 10:00:00', 'YYYY/MM/DD HH24:MI:SS'), '1x3', NULL);
-- Com estes novos dados, aparecerá uma contagem para os não clássicos também,
-- totalizando dois não clássicos e dois clássicos (com os dados já
-- existentes).

-------------------- Q4 --------------------
-- Selecionar a quantidade de jogos clássicos que ocorreram 
-- por mês no ano de 2018. Ordene o resultado do mês com 
-- maior quantidade para o de menor quantidade de jogos. 
SELECT EXTRACT(MONTH FROM P.data) AS mes, COUNT(*) AS qnt
FROM Partida P
INNER JOIN Joga J
	ON P.time1 = J.time1 AND P.time2 = J.time2
WHERE J.classico = 'S' AND EXTRACT(YEAR FROM P.data) = 2018
GROUP BY EXTRACT(MONTH FROM P.data)
ORDER BY COUNT(*) DESC;

-- Vamos inserir mais alguns times para definir mais jogos clássicos
INSERT INTO TIME (NOME, ESTADO, TIPO, SALDO_GOLS) VALUES ('CORINTHIANS', 'SP', 'PROFISSIONAL', 25);
INSERT INTO TIME (NOME, ESTADO, TIPO, SALDO_GOLS) VALUES ('SAO PAULO', 'SP', 'PROFISSIONAL', 18);

INSERT INTO JOGA (TIME1, TIME2, CLASSICO) VALUES ('CORINTHIANS', 'SAO PAULO', 'S');
INSERT INTO JOGA (TIME1, TIME2, CLASSICO) VALUES ('CORINTHIANS', 'PALMEIRAS', 'S');
INSERT INTO JOGA (TIME1, TIME2, CLASSICO) VALUES ('SAO PAULO', 'PALMEIRAS', 'S');

-- E vamos inserir mais partidas em 2018 para poder melhor visualizar os dados
-- agrupados
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('CORINTHIANS', 'SAO PAULO', TO_DATE('2018/09/10 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), '4X1', 'FORTALEZA');
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('CORINTHIANS', 'PALMEIRAS', TO_DATE('2018/05/25 09:00:00', 'YYYY/MM/DD HH24:MI:SS'), '1X0', NULL);
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('SAO PAULO', 'PALMEIRAS', TO_DATE('2018/04/30 15:00:00', 'YYYY/MM/DD HH24:MI:SS'), '0X2', 'FORTALEZA');
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('CORINTHIANS', 'PALMEIRAS', TO_DATE('2018/04/01 12:00:00', 'YYYY/MM/DD HH24:MI:SS'), '2X2', NULL);

-------------------- Q5 --------------------
-- Para cada time, selecionar: nome, estado, saldo de gols, 
-- e a quantidade de jogos clássicos que jogou por ano.
SELECT T.nome, T.estado, T.saldo_gols, classicas.ano, COUNT(classicas.ano) AS qnt_classicos
FROM Time T
-- Note que o count não conta valores nulos, portanto fazendo left join
-- os times que não jogaram nenhum jogo clássico ficam com o ano null
-- e portanto o count = 0, que é o que queremos. 
LEFT JOIN (
	-- Todas as partidas clássicas
	SELECT j.time1, j.time2, EXTRACT(YEAR FROM p.data) AS ano
	FROM Joga j
	INNER JOIN Partida p
		ON j.time1 = p.time1 AND j.time2 = p.time2
	WHERE j.classico = 'S'
) classicas
	ON T.nome = classicas.time1 OR T.nome = classicas.time2
GROUP BY T.nome, T.estado, T.saldo_gols, classicas.ano
ORDER BY T.nome, classicas.ano;

-- Com os dados atuais e os adicionados para as queries anteriores, já é 
-- possível verificar o funcionamento.

-------------------- Q6 --------------------
-- Selecionar nomes dos times profissionais que jogaram 
-- clássicos e não marcaram gols em pelo menos 2 jogos.
SELECT T.nome
FROM Time T 
INNER JOIN
(
	(
        SELECT DISTINCT J.time1 AS time
        FROM Joga J
        INNER JOIN Partida P
            ON J.time1 = P.time1 AND J.time2 = P.time2
        WHERE J.classico = 'S'
    )
	UNION 
    (
        SELECT DISTINCT J.time2 AS time
        FROM Joga J
        INNER JOIN Partida P
            ON J.time1 = P.time1 AND J.time2 = P.time2
        WHERE J.classico = 'S'
    )
) times -- Todos os times (distintos) que jogaram partidas clássicas
ON T.nome = times.time 
INNER JOIN 
(
    (
	SELECT time1 AS time
        FROM Partida
        WHERE placar LIKE '0X%'
    )
    	-- UNION ALL para selecionar todas as partidas em que
	-- o time marcou 0 gols como time 1 ou 2 e poder realizar
	-- o count. 
    UNION ALL
    (
        SELECT time2 AS time
        FROM Partida
        WHERE placar LIKE '%X0'
    )
) zero
    ON zero.time = T.nome
GROUP BY T.nome
HAVING COUNT(zero.time) >= 2;
-- Vamos adicionar mais uma partida do São Paulo em que ele marca 0 gols para
-- poder visualizar como resultado na query, já que ele tem apenas um jogo em
-- que não marcou nenhum gol.
INSERT INTO PARTIDA (TIME1, TIME2, DATA, PLACAR, LOCAL) VALUES ('CORINTHIANS', 'SAO PAULO', TO_DATE('2020/09/10 19:00:00', 'YYYY/MM/DD HH24:MI:SS'), '1X0', 'BELO HORIZONTE');

-------------------- Q7 --------------------
-- Selecionar a quantidade de times e a média do saldo de 
-- gols dos times por estado, por tipo de time. Ordenar o 
-- resultado por estado e depois por tipo de time.
SELECT estado, tipo, AVG(saldo_gols)
FROM Time
GROUP BY estado, tipo
ORDER BY estado, tipo;

-- Com os dados atuais e os adicionados para as queries anteriores, já é 
-- possível verificar o funcionamento.

-------------------- Q8 --------------------
-- Para os confrontos  “clássicos”  (Joga), selecione a 
-- quantidade de vezes que os 2 times já se enfrentaram (PARTIDA). 
SELECT J.time1, J.time2, COUNT(P.placar) as qnt_partidas
FROM Joga J
LEFT JOIN Partida P
    ON J.time1 = P.time1 AND J.time2 = P.time2
WHERE J.classico = 'S'
GROUP BY J.time1, J.time2;

-- Com os dados atuais e os adicionados para as queries anteriores, já é 
-- possível verificar o funcionamento.


-------------------- Q9 --------------------
-- Selecionar os times do estado de SP que jogaram em todos
-- os locais em que o “Santos” jogou.
SELECT DISTINCT T.nome
FROM Time T
INNER JOIN Partida P
    ON P.time1 = T.nome OR P.time2 = T.nome
INNER JOIN (
	-- Todos os locais que Santos jogou
    SELECT DISTINCT P.local
    FROM Partida P
    WHERE P.time1 = 'SANTOS' OR P.time2 = 'SANTOS'
) locais
    ON locais.local = P.local
WHERE T.estado = 'SP';

-- Com os dados atuais e os adicionados para as queries anteriores, já é 
-- possível verificar o funcionamento.


-------------------- Q10 --------------------
-- Selecionar os times com o menor saldo de gols em cada estado. 
-- Apresentar nome do time, estado e saldo de gols.  
SELECT nome, estado, saldo_gols
FROM Time
WHERE saldo_gols IN (
	SELECT MIN(saldo_gols) AS minimo
	FROM Time
	GROUP BY estado
)
-- Ordenando apenas para ficar mais bonito.
ORDER BY estado;

-- Perceba que haverá o mesmo estado repetido se houverem mais de um
-- time com o mesmo número de saldo de gols mínimos.

-- Para testar isso, vamos inserir mais um time no mesmo estado com o mesmo
--saldo de gols.
INSERT INTO TIME (NOME, ESTADO, TIPO, SALDO_GOLS) VALUES ('GUARATINGUETA', 'SP', 'AMADOR', 1);

