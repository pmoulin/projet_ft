<template>
  <div>
      <div id="headers">
          <div v-if="isConnect">
            <ul>
              <li>
                <a href="/">home</a>
              </li>
              <li>
                <router-link :to="{name : 'profile', params: {id : this.my_id, profile : null}}" >profile</router-link>
              </li>
              <li>
                <router-link :to="'/profile/' + this.my_id + '/create'">create profil</router-link>
              </li>
              <li>
                <a v-on:click="disconnect"> déconnexion</a>
              </li>
              <li>
                <router-link :to="'/profile/' + this.my_id + '/edit'" >edit profil</router-link>
              </li>
              <li>
                <router-link to="/tags">tags</router-link>
              </li>
              <li>
                <router-link :to="'/profile/'+ this.my_id +'/viewed'">profile vue</router-link>
              </li>
              <li>
                <router-link :to="'/profile/'+ this.my_id +'/visitor'">les visiteur de mon profile</router-link>
              </li>
              <li>
                <router-link to="/uploadImage">Ajouter des images</router-link>
              <li>
                <router-link to="/suggestion">suggestion</router-link>
              </li>
            </ul>
      </div>
    </div>
    <div id="app">
      <router-view :my_id="my_id"></router-view>
    </div>
  </div>
</template>

<script>
import axios from "axios";
import io from "socket.io-client";

export default {
  /* eslint-disable */
  // eslint-disable-next-line

  name: "App",
  mounted() {
    axios
      .get("http://localhost:3000/isConnected", { withCredentials: true })
      .then(res => {
        this.isConnect = res.data.connected;
        if (
          !this.isConnect &&
          this.$route.name != "connexion" &&
          this.$route.name != "Inscription"
        ) {
          this.$router.push({ name: "connexion" });
          console.log("");
        }
        this.my_id = res.data.id;
          this.socket.emit('first', this.my_id);
          this.socket.on("notif", data => {
            this.messages = [...this.messages, data];
          // console.log("this.message", this.messages, "id = " + this.my_id);
          });
      })
      .catch(e => {
        console.log(e);
      });

    // console.log(this.socket.id);

    // console.log(" : ", "message" + this.);
  },

  socket: {},
  data() {
    return {
      my_id : -1,
      isConnect: null,
      //socket
      message: "",
      messages: [],
      socket: io("localhost:3000")
    };
  },
  methods: {
    async disconnect() {
      const { data } = await axios.get("http://localhost:3000/disconnect", {
        withCredentials: true
      });
      const { connected } = data;
      this.isConnect = connected;
      this.status = connected ? "connected" : "disconnected";
      this.$router.push({ name: "connexion" });
    }
  }
};
</script>

<style>
#headers {
  background-color: white;
  height: 100px;
  width: 100%;
  border-bottom: black solid 1px;
}
ul {
  display: inline-flex;
}
li {
  list-style-type: none;
  margin-right: 20px;
}
/* Body */
#app {
  
  width: 80%;
  display : inline-block;
  margin : 30px 10% 0 10%;
  border : solid 1px black;
}
</style>