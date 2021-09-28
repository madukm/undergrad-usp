% Frederico Bulhões de Souza RIbeiro - 11208440
% Maria Eduarda Kawakami Moreira - 11218751

% Atividade 6 - Busca em profundidade forward e backward

node(a, b).
node(a, c).
node(b, d).
node(d, h).
node(h, d).
node(b, e).
node(e, i).
node(e, j).
node(c, f).
node(f, k).
node(c, g).

contains(H, [H|_]).

contains(H, [_|T]):-
    contains(H, T).
    

backward(S, G, path):-
    % transform G into a list
    path_b(S, [G], path). 

    % When S belongs in the temporary list, we assign it to the path  
    path_b(S, [S|path], [S|path]).

    path_b(S, [last_state|curr_path], path):-
        node(state, last_state),
        not(contains(state, curr_path)),
        path_b(S, [state, last_state|curr_path], path).


forward(EI, EF, path):-
    path_f(EF, [EI], path).

    path_f(EF, [EF|path], [EF|path]).

    path_f(EF, [Eint|curr_path], path):-
        node(Eint, E),
        not(contains(E, curr_path)),
        path_f(EF, [E, Eint|curr_path], path).
