<template>
    <div>
        <h1> Edit  => status => {{isconnect}}</h1>

        <p style='color:red' v-if="error != null">{{error}}</p>
        <form @submit.prevent="onSubmit">
        <ul>
            <li>firstname<input v-model="profile.first_name" type="text"></li>
            <li>Lastname<input v-model="profile.last_name" type="text"></li>
            <li>genre<input v-model="profile.genre" type="text"></li>
            <li>Age<input v-model="profile.age" type="text"></li>
            <li>orientation<input v-model="profile.orientation" type="text"></li>
            <li>bio<input v-model="profile.bio" type="text"></li>
            <li>??<input type='submit'></li>
        </ul>
        </form>
    </div>
</template>
<script>
/* eslint-disable */

    import axios from 'axios'   
    export default {
        name: 'editProfile',
        mounted() {
            this.profile.id = this.$route.params.id
            axios.get('http://localhost:3000/profile/' + this.profile.id + '/edit', {withCredentials : true}).then(res => {
            console.log(res.status)
                    const {profile} = res.data;
                    this.profile = profile;
            }).catch(err =>  {
                window.location = 'http://localhost:8080/'
            })


        },
        data() {
            return {
                test : null,
                profile : {
                    id : -1,
                    age : 0,
                    bio : "",
                    genre : "",
                    last_name : "",
                    first_name : "",
                    orientation : "",
                },
                error : null,
                isconnect : null,
            }
        },
        methods: {
            onSubmit() {
                console.log(this.error);
                if (this.verifParams()) {
                    this.error = 'succces';
                    axios.post('http://localhost:3000/profile/' + this.profile.id + '/edit', {profile : this.profile},{withCredentials : true})
                } else
                    this.error = 'Tout les champs doivent etre remplie';
            },

            verifParams() {
                if (this.profile !== null) {
                    if (this.profile.id && this.profile.bio && this.profile.genre && this.profile.orientation && this.profile.first_name && this.profile.last_name)
                        return true;
                }
                return false;
            }
        }
    }
</script>