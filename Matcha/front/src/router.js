import Router from "vue-router"
import Vue from "vue/dist/vue.js"
import VueAxios from 'vue-axios'
import axios from 'axios'

import home from "@/components/index"
import connexion from "@/components/connexion"
import inscription from "@/components/inscription"
import profile from "@/components/profils/profile"
import editProfile from "@/components/profils/edit"
import createProfile from "@/components/profils/create"
import tags from "@/components/profils/tags"
import viewed from '@/components/profils/viewed'
import visitor from '@/components/profils/visitor'
import uploadImage from "@/components/profils/uploadImage"

import suggestions from '@/components/suggestions'

Vue.use(VueAxios, axios)
Vue.use(Router)

export default new Router({

  mode: "history",
  routes: [
    {
      path: "/",
      name: "/home",
      component: home
    },
    {
      path: "/connexion",
      name: "connexion",
      component: connexion
    },
    {
      path: "/inscription",
      name: "Inscription",
      component: inscription
    },
    {
      path: "/profile/:id",
      name: "profile",
      component: profile
    },
    {
      path: "/profile/:id/create",
      name: "createProfile",
      component: createProfile
    },
    {
      path: "/profile/:id/edit",
      name: "editProfile",
      component: editProfile
    },
    {
      path: "/tags",
      name: "tags",
      component: tags
		},
		{
			path: '/profile/:id/viewed',
			name: 'viewed',
			component: viewed
		},
		{
			path: '/profile/:id/visitor',
			name: 'visitor',
			component: visitor
    },
    {
      path: "/uploadImage",
      name: "uploadImage",
      component: uploadImage
    },
    {
			path: '/suggestions',
			name: 'suggestions',
			component: suggestions
		},
  ]
})