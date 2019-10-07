<template>
    <div id="connection">
        <form @submit.prevent="onSubmit"> 
            <input type='text' v-model="login" placeholder="login">
            <input type='text' v-model="pwd" placeholder="pwd">
            <input type='submit'>
        </form>
        <router-link to="Inscription">Pas encore de compte ?</router-link>
    </div>
</template>

<script>
import axios from "axios";
/* eslint-disable */
export default {
  name: "connection",
  async mounted() {
    this.getPos();
    const { data } = await axios.get("http://localhost:3000/isConnected", {
      withCredentials: true
    });
    
    const { connected } = data;
    this.isConnected = connected;
    if (connected)
       window.location =  '/'
  },

  data() {
    return {
      isConnected: null,
      status: null,
      pos: Object,
      login: 'login',
      pwd: 'password'
    };
  },

  methods: {
    setPos(position) {
      this.pos.lat = position.coords.latitude;
      this.pos.lon = position.coords.longitude;
    },
    getPos() {
      if (navigator.geolocation)
        navigator.geolocation.getCurrentPosition(this.setPos);
      else this.pos = null;
    },
    async onSubmit() {
      if (this.pos === null) this.getPos();
      const { data } = await axios.post(
        "http://localhost:3000/connection",
        {
          pos: {
            lat: this.pos.lat,
            lon: this.pos.lon
          },
          login: this.login,
          pwd: this.pwd
        },
        { withCredentials: true }
      );
      const { connected } = data;
      this.isConnected = connected;
      if (connected)
        window.location = '/'
    }
  }
};
</script>