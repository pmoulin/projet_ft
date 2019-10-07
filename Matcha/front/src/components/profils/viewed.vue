<template>
<div>
    <!-- <h1>{{profiles}}</h1> -->

    <div v-if="profiles != null">
        <ul v-for="(profile, index) in this.profiles" :key="index">
            <li>{{index}}</li>
            <li> profile view : <a :href="'/profile/' + id">{{profile.first_name}} {{profile.last_name}}</a></li>
        </ul>
    </div>
    </div>
</template>
<script>
// eslint-disable-next-line
/* eslint-disable */
    import axios from 'axios'
    export default {
        name : 'viewed',
        async mounted() {
            this.id = this.$route.params.id,
            axios.get('http://localhost:3000/profile/' + this.id + '/viewed', {withCredentials : true}).then(res => { 
                const {profile} = res.data;
                this.profiles = profile;
            }).catch(err => {
                console.log('err => ' + err);
                // window.location = 'http://localhost:8080/';
            })
            console.log(this.profiles);
        },
        data() {
            return {
                id : null,
                profiles : {
                    age : 0,
                    bio: "",
                    first_name: "",
                    genre: "",
                    id: -1,
                    last_connection: "",
                    last_name: "",
                    lat: "",
                    lon: "",
                    nb_like: 0,
                    nb_vue: 0,
                    orientation: "",
                    updated_at: "",
                    user_id: -1,
                }
            }
        }
    }
</script>