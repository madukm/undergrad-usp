var app = new Vue({
    el: '#app',
    data: {
        errors: [],
        name: null,
        surname: null,
        birthday: null,
        city: null,
        signo: null,
    },
    methods: {
        checkForm: function (e){
            if(!this.name){
                this.errors.push('First name required');
            }
            if(!this.surname){
                this.errors.push('Surname required');
            }
            if(!this.city){
                this.errors.push('City required');
            }
            if(!this.birthday){
                this.errors.push('Birth date required');
            }else if(!this.validDate(this.birthday)){
                this.errors.push('A valid date is required')
            }
            if(!this.signo){
                this.errors.push('Signo required');
            }
            if (!this.errors.length) {
                return true;
              }
        
              e.preventDefault();
        },
        validDate: function(date){
            var date_regex = /^(0[1-9]|1[0-2])\/(0[1-9]|1\d|2\d|3[01])\/(19|20)\d{2}$/;
            return (date_regex.test(date));
        }

    }

});