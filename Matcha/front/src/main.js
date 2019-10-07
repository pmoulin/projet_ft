import Vue from 'vue/dist/vue.js'
import App from '@/App'
import router from '@/router.js'

Vue.config.productionTip = false

// Vue.config.productionTip = false

new Vue({
	el: '#app',
	router,
	components: {
		App
	},
	template: '<app/>'
})
