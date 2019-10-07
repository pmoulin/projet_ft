<template>
  <div class="container">
    <div>
      <h3>Ta photo de profil</h3>
      <h4 v-if="!profilePicture.length">Vous n'avez pas encore de photo de profil</h4>
      <div v-if="profilePicture.length">
        <img :src="profilePicture[0].path">
      </div>
    </div>
    <br>

    <div>
      <h3>Tes photos</h3>
      <h4 v-if="!userImages.length">Tu n'as pas de photo pour le moment</h4>
      <div v-if="userImages.length">
        <h4>Séléctionne ta photos de profil ou supprime des photos</h4>
        <div v-for="(userImage, key) in userImages" :key="key">
          <input type="radio" :id="userImage.id" :value="userImage.id" v-model="picked">
          <label :for="userImage.id">
            <img :src="userImage.path">
            <button v-on:click="deleteImage(userImage)">Supprimer</button>
          </label>
        </div>
        <br>
        <button v-on:click="setProfilePicture()">Changer la photo de profil</button>
      </div>
    </div>
    <br>

    <div>
      <h3>Tu peux encore ajouter {{maxUpload}} photos !</h3>
      <label>
        Ajoute des photos
        <input
          type="file"
          id="files"
          ref="files"
          accept="image/*"
          multiple
          v-on:change="handleFilesUpload()"
        >
      </label>
      <p>{{error}}</p>
    </div>

    <div>
      <div v-for="(file, key) in files" :key="key">
        <img class="preview" v-bind:ref="'image'+parseInt( key )">
        {{ file.name }}
        <button v-on:click="deleteInUploadFile(key)">Supprimer</button>
      </div>
    </div>
    <br>
    <button v-on:click="submitFiles()">Ajouter les photos</button>
    <div></div>
  </div>
</template>

<script>
import axios from "axios";
/* eslint-disable */

export default {
  data() {
    return {
      userImages: [],
      files: [],
      picked: 0,
      maxUpload: 5,
      inUpload: 0,
      error: "",
      profilePicture: []
    };
  },

  async mounted() {
    await this.getUserImages();
    await this.getProfilePicture();
  },

  methods: {
    /*
        Submits files to the server
      */

    async getProfilePicture() {
      const { data } = await axios.get(
        "http://localhost:3000/getProfilePicture",
        { withCredentials: true }
      );
      console.log(data);
      this.profilePicture = data.profilePicture;
      if (this.profilePicture.length) {
        this.picked = this.profilePicture[0].id;
      }
    },

    async getUserImages() {
      const { data } = await axios.get("http://localhost:3000/getUserImages", {
        withCredentials: true
      });

      if (data.error) {
        window.location = "http://localhost:8080/";
      }

      this.userImages = data.images;
      this.maxUpload = 5 - this.userImages.length;
    },

    async submitFiles() {
      let formData = new FormData();

      console.log("submittedfiles", this.files);
      for (var i = 0; i < this.files.length; i++) {
        let file = this.files[i];

        formData.append("files[" + i + "]", file);
      }

      await axios.post("http://localhost:3000/uploadImages", formData, {
        withCredentials: true,
        headers: {
          "Content-Type": "multipart/form-data"
        }
      });
      this.files = [];
      await this.getUserImages();
    },

    /*
        Handles the uploading of files
      */
    handleFilesUpload() {
      let uploadedFiles = this.$refs.files.files;
      this.inUpload += uploadedFiles.length;

      if (this.inUpload > this.maxUpload) {
        this.error = `Vous ne pouvez pas ajouter autant de photos, plus que ${
          this.maxUpload
        } places disponibles`;
      } else {
        this.error = "";
        for (var i = 0; i < uploadedFiles.length; i++) {
          this.files.push(uploadedFiles[i]);
        }

        console.log(this.files);
        this.getImagePreviews();
      }
    },

    async setProfilePicture() {
      await axios.post(
        "http://localhost:3000/setProfilePicture",
        { imageId: this.picked },
        {
          withCredentials: true
        }
      );
      await this.getProfilePicture();
    },

    /*
        Gets the preview image for the file.
      */
    getImagePreviews() {
      for (let i = 0; i < this.files.length; i++) {
        if (/\.(jpe?g|png|gif)$/i.test(this.files[i].name)) {
          let reader = new FileReader();

          reader.addEventListener(
            "load",
            function() {
              this.$refs["image" + parseInt(i)][0].src = reader.result;
            }.bind(this),
            false
          );

          reader.readAsDataURL(this.files[i]);
        }
      }
    },

    deleteInUploadFile(index) {
      this.files.splice(index, 1);
      this.inUpload--;
      this.getImagePreviews();
    },

    async deleteImage(image) {
      await axios.post(
        "http://localhost:3000/deleteImage",
        { image },
        {
          withCredentials: true
        }
      );
      await this.getUserImages();
      await this.getProfilePicture();
    }
  }
};
</script>