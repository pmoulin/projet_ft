<template>
    <div>
        <h1>Inscription</h1>
        <form @submit.prevent="onSubmit">
            <input type='text' v-model="login" placeholder="login">
            <input type='text' v-model="pwd" placeholder="pwd">
            <input type='text' v-model="email" placeholder="mail">
            <input type='text' v-model="first_name" placeholder="prenom">
            <input type='text' v-model="last_name" placeholder="nom">
            <input type='submit'>
        </form>
        <router-link to="Connexion">Deja un compte ?</router-link>
    </div>
</template>

<script>
import axios from "axios";
/* eslint-disable */

export default {
  name: "inscription",
  async mounted() {
    const { data } = await axios.get("http://localhost:3000/isConnected", {
      withCredentials: true
    });
    const { connected } = data;
    this.isConnected = connected;
    if (connected)
      window.location = '/'
  },

  data() {
    return {
      login: null,
      pwd: null,
      isConnected: "",
      status: null,
      first_name: null,
      last_name: null,
      email: null
    };
  },

  methods: {
    async onSubmit() {
      await axios.post("http://localhost:3000/register", {
        login: this.login,
        pwd: this.pwd,
        first_name: this.first_name,
        last_name: this.last_name,
        email: this.email
      });
    }
  }
};

</script>