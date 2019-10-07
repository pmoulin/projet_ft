<template>
  <div>
      <ul v-for="(profile, key) in profiles" :key="key" style ="border : 1px solid black; width:100px, height : 100px">
          <li>{{profile.firstname}}</li>
      </ul>
  </div>
</template>

<script>
import axios from "axios";
  /* eslint-disable */
  // eslint-disable-next-line
    export default {
        mounted() {
            axios.get("http://localhost:3000/suggestion", { withCredentials: true }).then( res => {
                this.profiles = res.data.candidate
            }).catch(err => {
                console.log(err);
            })
        },

        data() {
            return {
                profiles : {},    
            }
        }
    }
</script>
