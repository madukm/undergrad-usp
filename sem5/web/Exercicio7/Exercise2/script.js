var app = new Vue({
    el: '#app',
    data() {
        return {
            searchQuery: null,
            items: [
                { title: 'Batman'},
                { title: 'Mulher-Maravilha'},
                { title: 'Homem-Aranha'},
                { title: 'Hulk'},
                { title: 'Homem de Ferro'},
                { title: 'Viuva negra'},
                { title: 'Wolverine'},
                { title: 'Super Homem'},
                { title: 'Coringa'},
            ],
        };        
    },
    computed: {
        resultQuery(){
            if(this.searchQuery){
                return this.items.filter((item)=>{ 
                    return this.searchQuery.toLowerCase().split(' ').every(c => item.title.toLowerCase().includes(c))
                })
            }else{
                return this.items;
            }
        }
    }
})

