 <template>
    <div>
        <div id="part_left">
            <img class="profile_picture" :src="profile.picture">
            <ul class="list">
                <li>Score</li>
                <li>visite reçu</li>
                <li>Like reçu </li>
            </ul>
            <ul>
                <li>42424242</li>
                <li>{{profile.nb_vue}}</li>
                <li>{{profile.nb_like}}</li>
            </ul>
        </div>
        
        <div id="part_right">
        <div v-if="parseInt(this.$route.params.id) === parseInt(this.my_id)">
            <button>EDit</button>
        </div>
        <div v-else>
            <button>Like</button>
        </div>
            <div class="content">
                <h1>{{profile.first_name + ' ' + profile.last_name}}</h1>
                <h2>{{profile.age}} ans, {{profile.city}}</h2>
                <h2>{{profile.country}}</h2>
            </div>
            <div class="content">
                <p> je suis recherche {{profile.orientation}}
                <h3>Bio : </h3>
                <span>Utque proeliorum periti rectores primo catervas densas opponunt et fortes, deinde leves armaturas, post iaculatores ultimasque subsidiales acies, si fors adegerit, iuvaturas, ita praepositis urbanae familiae suspensae digerentibus sollicite, quos insignes faciunt virgae dexteris aptatae velut tessera data castrensi iuxta vehiculi frontem omne textrinum incedit: huic atratum coquinae iungitur ministerium, dein totum promiscue servitium cum otiosis plebeiis de vicinitate coniunctis: postrema multitudo spadonum a senibus in pueros desinens, obluridi distortaque lineamentorum conpage deformes, ut quaqua incesserit quisquam cernens mutilorum hominum agmina detestetur memoriam Samiramidis reginae illius veteris, quae teneros mares castravit omnium prima velut vim iniectans naturae, eandemque ab instituto cursu retorquens, quae inter ipsa oriundi crepundia per primigenios seminis fontes tacita quodam modo lege vias propagandae posteritatis ostendit.</span>
                <div v-if="profile.tags">
                    <h3>Mes centre d'interer : </h3>
                    <div v-for="(tag, index) in profile.tags" :key="index">
                        <span>#{{tag}}</span>
                    </div>
                </div>
            </div>
        </div>
        <!-- <div>
            <div v-if="blocke != null">
                <form v-if="blocke === 0" @submit.prevent="Likes">
                    <input v-if="like === 0" type="submit" value="like">
                    <input v-if="like === 1" type="submit" value="unlike">
                </form>
                <form @submit.prevent="Blocked">
                    <input v-if="blocke === 0" type="submit" value="blocke">
                    <input v-if="blocke === 1" type="submit" value="unblock">
                </form>
            </div>
            <h1>genre</h1>
            <p v-if="genre"> {{genre}}</p>
            <h1>bio</h1>
            <p v-if="bio"> {{bio}}</p>
        </div> -->
    </div>
</template>

<script>

import axios from 'axios'
export default {
/* eslint-disable */
    props : {
        my_id : Number,
    },
    name : 'profils',
    updated: function() {
        this.id = this.$route.params.id;
         if (String(this.profile.id) != String(this.$route.params.id)) {
            console.log(this.id,"ojerpogjorgj", this.$route.params.id)
            this.getProfile();    
         }
    },

    mounted() {
        this.getProfile();
    },
    data() {
        return {
            test : null,
            orientationType : [
                    "une Femme",
                    "un Homme",
                    "une Femme ou un Homme",
                    "un Non Binaire",
                    "un(e)Transexuelle",
                    "de Tout type de personne",
                ],
            profile : {
                id : null,
                bio : null,
                tags : [],
                genre : null,
                last : null,
                first : null,
                orientation : null,
                nb_like : null,
                nb_vue : null,
            },
            blocke : 0,
            like : 0,
            id : 0,
            name : null,
            bio : null,
            genre : null,
        }
    },
    methods: {
        getProfile() {
            if (this.profile.id != this.$route.params.id) {
                this.id = this.$route.params.id,
                console.log('test');
                axios.get('http://localhost:3000/profile/' + this.id , {withCredentials : true}).then(res => { 
                    const {profile, like, blocke} = res.data
                    // data = resp.data
                    // this.test = data;
                        this.blocke = blocke;
                        this.profile = profile;
                        // console.log('test', res.data.profile);
                        this.profile.id = this.profile.user_id;
                        this.profile.nb_vue = 100000001;
                        console.log("new date : ", new Date());
                        console.log("birtday = ", new Date(this.profile.birthday));
                        this.profile.age = (new Date()).getFullYear() - (new Date(this.profile.birthday)).getFullYear()
                        this.profile.orientation = this.orientationType[this.profile.orientation]
                        this.profile.city = "Paris"
                        this.profile.country = "France"
                        this.profile.nb_like = (parseInt(this.profile.nb_like) > 100000000) ? "+10000000" : this.profile.nb_like; 
                        this.profile.nb_vue = (parseInt(this.profile.nb_vue) > 100000000) ? "+10000000" : this.profile.nb_vue; 
                        this.profile.picture = '/picture/picture.jpg';
                        this.like = like; // verif si utilisateur a deja liker se profile
                }).catch(err =>  {
                    // console.log(err);
                    window.location = 'http://localhost:8080/';
                })
            }
        },

        Likes() {
            if (this.like === 1) {
                console.log(this.id, this.profile.id)
                axios.post('http://localhost:3000/profile/' + this.id +'/disLike', {id : this.profile.id},{withCredentials : true}).then(res => {
                    if (res.data = 1)
                            this.like = 0;
                })
            }
            else if (this.like === 0) {
                axios.post('http://localhost:3000/profile/' + this.id +'/addLike', {id : this.profile.id},{withCredentials : true}).then(res => {
                    if (res.data = 1)
                        this.like = 1;
                })
            }
        },
        Blocked() {
            if (this.blocke === 0) {
                axios.post( 'http://localhost:3000/profile/' + this.id +'/block', {id : this.profile.id},{withCredentials : true}).then(res => {
                    if (res.data = 1)
                        this.blocke = 1;
                })
            } else {
                axios.post('http://localhost:3000/profile/' + this.id +'/unblock', {id : this.profile.id},{withCredentials : true}).then(res => {
                    if (res.data = 1)
                        this.blocke = 0;
                })
            }
        },
    },
}
</script>
<style lang="scss">
    #part_left {
        border : solid grey 1px;
        display : inline-block;
        float: left;
        width :20%;
        .profile_picture {
            width: 90%;
            margin : 0 5% 0 5%;
            border : solid blue 1px;
        }
        ul {
            width : 90%;
            text-align :center;
            margin : 0 5% 0 5%;
            padding-left : 0%;
            li {
                width: 30%
            }
            span {
                text-align :center;
            }
        }
    }
    h1 {

    }
    #part_right{
        width: 70%;
        margin-left: 5%;
        display : inline-block;
        border : solid green 3px;
        .content {
            border : solid black 1px;
            padding-left : 15px;
            margin-bottom : 50px;
            h1 {
                font-size: 4rem;
                margin : 0;
                
            }
            h2 {
                margin-bottom : 2px;
                margin-top : 2px;
            }
            span {
                margin : 0 0 1% 1%;
                display: inline-block;
                text-align: left;
            }
        }
    }
    

</style>
