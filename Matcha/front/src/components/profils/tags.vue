<template>
  <div id="show-tags">
    <h3>Tes tags actuels</h3>
    <div
      v-for="userTag in userTags"
      :key="userTag.name"
      v-on:click="deleteTag(userTag.tag_id)"
      class="user-tag"
    >
      #{{userTag.name}}
      <br>
    </div>
    <h3>Ajoute des tags</h3>
    <form @submit.prevent="onSubmit">
      <input type="text" v-model="search" placeholder="search tags">
      <input type="submit">
    </form>
    <div v-for="tag in filteredTags" :key="tag.id" class="single-tag">
      <article v-on:click="selectTag(tag)">
        #{{ tag.name }}
        <div>{{tag.nb_selected}} user</div>
      </article>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      tags: [],
      search: "",
      userTags: []
    };
  },

  async mounted() {
    await this.getTags();
    await this.getUserTags();
  },

  computed: {
    filteredTags: function() {
      const hashtag = this.search[0] === "#" ? true : false;
      const tag = this.tags.filter(tag => {
        return tag.name.match(this.search.slice(hashtag ? 1 : 0));
      });
      if (tag.length >= 5) return tag.slice(0, 5);
      return tag;
    }
  },

  methods: {
    async getUserTags() {
      const userTags = await axios.get("http://localhost:3000/getUserTags", {
        withCredentials: true
      });
      this.userTags = userTags.data.tags;
    },

    async getTags() {
      const allTags = await axios.get("http://localhost:3000/getAllTags");
      this.tags = allTags.data.tags.sort(
        (a, b) => b.nb_selected - a.nb_selected
      );
    },

    selectTag(tag) {
      this.search = tag.name;
    },

    async onSubmit() {
      const hashtag =
        this.search[0] === "#" ? this.search.slice(1) : this.search.slice(0);
      await axios.post(
        "http://localhost:3000/addTag",
        {
          tagName: hashtag
        },
        { withCredentials: true }
      );
      await this.getUserTags();
      await this.getTags();
    },

    async deleteTag(tagId) {
      await axios.post(
        "http://localhost:3000/deleteTag",
        { tagId },
        { withCredentials: true }
      );
      await this.getUserTags();
      await this.getTags();
    }
  }
};
</script>

<style scoped>
/* #show-tags {
  max-width: 800px;
  margin: 0px auto;
}
.single-tag {
  padding: 20px;
  margin: 20px 0;
  box-sizing: border-box;
  background: #eee;
  border: 1px dotted #aaa;
}

#show-tags a {
  color: #444;
  text-decoration: none;
}
input[type="text"] {
  padding: 8px;
  width: 100%;
  box-sizing: border-box;
} */
</style>
