function add_link(paragraph){
  let link = document.createElement('a')
  link.href = 'index.html'
  link.innerHTML = ' Home'
  link.style.fontWeight = 'bold'
  link.style.textDecoration = 'none'
  paragraph.appendChild(link)
  console.log(paragraph)
}

function split_sentences(paragraph){
  paragraph.innerHTML = paragraph.innerHTML.match( /[^\.!\?]+[\.!\?]+/g ).join('<br>')
}

function count_words(paragraph){
  paragraph.innerHTML = paragraph.innerHTML.split(' ').length + '<br>' + paragraph.innerHTML;
}

function highlight(paragraph){
  let words = paragraph.innerHTML.split(' ')
  for(let i=0; i<words.length; i++){
    if(words[i].length >= 8){
      words[i] = "<span style=\"background-color: pink;\">" + words[i] + "</span> "
    }
    else if(words[i].length == 6){
      words[i] = "<span style=\"background-color: blue;\">" + words[i] + "</span> "
    }
    else if(words[i].length == 5 || words[i.length == 4]){
      words[i] = "<span style=\"background-color: purple;\">" + words[i] + "</span> "
    }
  }
  paragraph.innerHTML = words.join(' ')
  console.log(paragraph.innerHTML)
}

var paragraph = document.getElementsByTagName('p')[0]
count_words(paragraph)
highlight(paragraph)
split_sentences(paragraph)
add_link(paragraph)



