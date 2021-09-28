SELECT T.nome, COUNT(zero.time)
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
) times
ON T.nome = times.time 
INNER JOIN 
(
    (
	SELECT time1 AS time
        FROM Partida
        WHERE placar LIKE '0X%'
    )
    -- UNION ALL para selecionar todas as partidas em que
	-- o time marcou 0 gols como time 1 ou 2. 
    UNION
    (
        SELECT time2 AS time
        FROM Partida
        WHERE placar LIKE '%X0'
    )
) zero
    ON zero.time = T.nome
GROUP BY T.nome
--HAVING COUNT(zero.time) >= 2;