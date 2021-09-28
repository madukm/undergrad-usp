document.getElementById('lib-button').addEventListener('click', makeMadTalk);

function makeMadTalk(){
  noun = document.getElementById('noun');
  adjective = document.getElementById('adjective');
  person = document.getElementById('person');
  let sentence = document.createElement('p');
  sentence.innerHTML += person.value + ' really likes ' + adjective.value + ' ' + noun.value + '.';
  document.getElementsByTagName('div')[0].appendChild(sentence);
}

