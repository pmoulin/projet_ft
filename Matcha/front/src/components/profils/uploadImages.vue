<template>
  <div class="container">
    <div>
      <label>
        Files
        <input
          type="file"
          id="files"
          ref="files"
          accept="image/*"
          multiple
          v-on:change="handleFilesUpload()"
        >
      </label>
    </div>
    <div>
      <div v-for="(file, key) in files" :key="key">
        <input type="radio" :id="key" :value="key" v-model="picked">
        <label :for="key">
          <img class="preview" v-bind:ref="'image'+parseInt( key )">
          {{ file.name }}
        </label>
      </div>
      <span>Choisi : {{ picked }}</span>
    </div>
    <br>
    <button v-on:click="submitFiles()">Ajouter les photos</button>
    <div></div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      files: [],
      base64Files: [],
      picked: ""
    };
  },

  methods: {
    /*
        Submits files to the server
      */
    async submitFiles() {
      // let formData = new FormData();

      // for (var i = 0; i < this.files.length; i++) {
      //   let file = this.files[i];

      //   formData.append("files[" + i + "]", file);
      // }

      console.log(this.picked)
      console.log(this.base64Files)
      // formData.append("index", this.picked)

      await axios
        .post("http://localhost:3000/uploadImages", {files: this.base64Files, picked: this.picked}, { withCredentials: true })
    },

    /*
        Handles the uploading of files
      */
    handleFilesUpload() {
      let uploadedFiles = this.$refs.files.files;

      for (var i = 0; i < uploadedFiles.length; i++) {
        this.files.push(uploadedFiles[i]);
      }

      this.getImagePreviews();
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
              this.base64Files.push(reader.result)
              this.$refs["image" + parseInt(i)][0].src = reader.result;
            }.bind(this),
            false
          );

          reader.readAsDataURL(this.files[i]);
        }
      }
    }
  }
};
</script>