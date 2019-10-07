<template>
  <div>
    <h1>CREATE => status => {{isconnect}}</h1>

    <form @submit.prevent="onSubmit">
      <ul>
        <li>firstname
          <input v-model="profile.first" type="text">
        </li>
        <li>Lastname
          <input v-model="profile.last" type="text">
        </li>
        <li>genre
          <input v-model="profile.genre" type="text">
        </li>
        <li>orientation
          <input v-model="profile.orientation" type="text">
        </li>
        <li>bio
          <input v-model="profile.bio" type="text">
        </li>
        <br>
        <upload-image url name :max_files="max"></upload-image>
        <li>??
          <input type="submit">
        </li>
      </ul>
    </form>
  </div>
</template>
<script>
/* eslint-disable */

import axios from "axios";
import UploadImage from "vue-upload-image";
export default {
  name: "createProfile",
  mounted() {
    (this.profile.id = this.$route.params.id),
      axios
        .get("http://localhost:3000/isconnect", { withCredentials: true })
        .then(res => {
          console.log(res.status);
          this.isconnect = res.data;
        });
  },
  data() {
    return {
      profile: {
        id: null,
        isconnect: null,
        bio: null,
        genre: null,
        last: null,
        first: null,
        max: 5
      },
      orientation: null
    };
  },
  methods: {
    onSubmit() {
      axios.post(
        "http://localhost:3000/profile/" + this.profile.id + "/create",
        { profile: this.profile },
        { withCredentials: true }
      );
    }
  }
};
</script>