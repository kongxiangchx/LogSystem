#include "chx/config.h"
#include "chx/log.h"
#include "chx/lock.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <sstream>
#include <thread>

#if 0
chx::ConfigVar<int>::ptr g_int_value_config =
    chx::Config::Lookup("system.port", (int)8080, "system port");

// chx::ConfigVar<float>::ptr g_intx_value_config =
//     chx::Config::Lookup("system.port", (float)8080, "system port");

chx::ConfigVar<float>::ptr g_float_value_config = 
    chx::Config::Lookup("system.value", 10.0f, "system value");

chx::ConfigVar<std::vector<int> >::ptr g_int_vec_value_config =
    chx::Config::Lookup("system.int_vec", std::vector<int>{1,2}, "system int vec");

chx::ConfigVar<std::list<int> >::ptr g_int_list_value_config =
    chx::Config::Lookup("system.int_list", std::list<int>{3,4}, "system int list");

chx::ConfigVar<std::set<int> >::ptr g_int_set_value_config =
    chx::Config::Lookup("system.int_set", std::set<int>{5,6}, "system int set");

chx::ConfigVar<std::unordered_set<int> >::ptr g_int_uset_value_config =
    chx::Config::Lookup("system.int_uset", std::unordered_set<int>{7,8}, "system int uset");

chx::ConfigVar<std::map<std::string, int> >::ptr g_str_int_map_value_config =
    chx::Config::Lookup("system.str_int_map", std::map<std::string, int>{{"k",2}}, "system str int map");

chx::ConfigVar<std::unordered_map<std::string, int> >::ptr g_str_int_umap_value_config =
    chx::Config::Lookup("system.str_int_umap", std::unordered_map<std::string, int>{{"q",3}}, "system str int umap");

void print_yaml(const YAML::Node node, int level) {
    if(node.IsScalar()) {
        CHX_LOG_INFO(CHX_LOG_ROOT()) << node.Scalar() << " - " << node.Tag() << " - " << level;
    }
    else if(node.IsNull()) {
        CHX_LOG_INFO(CHX_LOG_ROOT()) << "NULL - " << node.Tag() << " - " << level;
    }
    else if(node.IsMap()) {
        for(auto it = node.begin(); it != node.end(); ++it) {
            CHX_LOG_INFO(CHX_LOG_ROOT()) << it->first << " - " << it->second.Tag();
        }
    }
}

void dfs_yaml(YAML::Node node) {
    if(node.IsMap()) {
        std::cout<<"Map: "<<std::endl;
        for(auto it = node.begin(); it != node.end(); ++it) {
            if(it->second.IsScalar()) {
                std::cout<< it->first << " : " << it->second << std::endl;
            }
            else {
                std::cout<< it->first << std::endl;
                dfs_yaml(it->second);
            }
        }
    }
    else if(node.IsSequence()) {
        std::cout<<"Seq: "<<std::endl;
        for(auto it : node) {
            dfs_yaml(it);
        }
    }
    else if(node.IsScalar()) {
        std::cout<< node << std::endl;
    }
}

void test_yaml() {
    YAML::Node root = YAML::LoadFile("/home/chx/Git/LogSystem/bin/conf/test.yml");
    //std::cout<<root<<std::endl;
    chx::Config::LoadFromYaml(root);
    //print_yaml(root, 0);
    //dfs_yaml(root);
    //CHX_LOG_INFO(CHX_LOG_ROOT()) << root;
}

void test_config() {
    CHX_LOG_INFO(CHX_LOG_ROOT()) << "before:" << g_int_value_config->getValue();
    CHX_LOG_INFO(CHX_LOG_ROOT()) << "before:" << g_float_value_config->toString();

#define XX(g_var, name, prefix) \
    {   \
        auto g = g_var->getValue();    \
        for(auto& i : g) {  \
            CHX_LOG_INFO(CHX_LOG_ROOT()) << #prefix " " #name ": " << i;    \
        }   \
        CHX_LOG_INFO(CHX_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString();   \
    }

#define XX_M(g_var, name, prefix) \
    {   \
        auto g = g_var->getValue();    \
        for(auto& i : g) {  \
            CHX_LOG_INFO(CHX_LOG_ROOT()) << #prefix " " #name ": {" \
                    << i.first << " - " << i.second << "}";    \
        }   \
        CHX_LOG_INFO(CHX_LOG_ROOT()) << #prefix " " #name " yaml: " << g_var->toString();   \
    }

    XX(g_int_vec_value_config, int_vec, before);
    XX(g_int_list_value_config, int_list, before);
    XX(g_int_set_value_config, int_set, before);
    XX(g_int_uset_value_config, int_uset, before);
    XX_M(g_str_int_map_value_config, str_int_map, before);
    XX_M(g_str_int_umap_value_config, str_int_umap, before);

    YAML::Node root = YAML::LoadFile("/home/chx/Git/LogSystem/bin/conf/test.yml");
    chx::Config::LoadFromYaml(root);

    CHX_LOG_INFO(CHX_LOG_ROOT()) << "after:" << g_int_value_config->getValue();
    CHX_LOG_INFO(CHX_LOG_ROOT()) << "after:" << g_float_value_config->toString();
    
    XX(g_int_vec_value_config, int_vec, after);
    XX(g_int_list_value_config, int_list, after);
    XX(g_int_set_value_config, int_set, after);
    XX(g_int_uset_value_config, int_uset, after);
    XX_M(g_str_int_map_value_config, str_int_map, after);
    XX_M(g_str_int_umap_value_config, str_int_umap, after);
#undef XX
#undef XX_M
}

#endif
#if 0
class Person {
public:
    Person() {};
    std::string m_name;
    int m_age = 0;
    bool m_sex = 0;
    std::string toString() const {
        std::stringstream ss;
        ss << "[Person name=" << m_name
            << " age=" << m_age
            << " sex=" << m_sex
            << "]";
        return ss.str();
    }
    bool operator == (const Person& p) const {
        return m_name == p.m_name && m_age == p.m_age && m_sex == p.m_sex;
    }
};

namespace chx {
template<>
class LexicalCast<std::string, Person> {
public:
    Person operator()(const std::string& v) {
        YAML::Node node = YAML::Load(v);
        Person p;
        p.m_name = node["name"].as<std::string>();
        p.m_age = node["age"].as<int>();
        p.m_sex = node["sex"].as<bool>();
        return p;
    }
};

template<>
class LexicalCast<Person, std::string> {
public:
    std::string operator()(const Person& v) {
        YAML::Node node;
        node["name"] = v.m_name;
        node["age"] = v.m_age;
        node["sex"] = v.m_sex;
        std::stringstream ss;
        ss << node;
        return ss.str();
    }
};
}

chx::ConfigVar<Person>::ptr g_person =
    chx::Config::Lookup("class.person", Person(), "system person");

chx::ConfigVar<std::map<std::string, Person> >::ptr g_person_map =
    chx::Config::Lookup("class.map", std::map<std::string, Person>(), "system person");

chx::ConfigVar<std::map<std::string, std::vector<Person> > >::ptr g_person_vec_map =
    chx::Config::Lookup("class.vec_map", std::map<std::string, std::vector<Person> >(), "system person");

void test_class() {
    CHX_LOG_INFO(CHX_LOG_ROOT()) << "before: " << g_person->getValue().toString() << " - " << g_person->toString();

#define XX_PM(g_var, prefix)    \
    {   \
        auto m = g_var->getValue();  \
        for(auto& i : m) {  \
            CHX_LOG_INFO(CHX_LOG_ROOT()) << prefix << ": " << i.first << "- " << i.second.toString();   \
        }   \
        CHX_LOG_INFO(CHX_LOG_ROOT()) << prefix << ": size=" << m.size();    \
    }

    g_person->addListener([](const Person& old_value, const Person& new_value) {
        CHX_LOG_INFO(CHX_LOG_ROOT()) << "old_value=" << old_value.toString()
                << " new_value=" << new_value.toString();
    });

    XX_PM(g_person_map, "class.map before");
    CHX_LOG_INFO(CHX_LOG_ROOT()) << "before: " << g_person_vec_map->toString();
    

    YAML::Node root = YAML::LoadFile("/home/chx/Git/LogSystem/bin/conf/test.yml");
    chx::Config::LoadFromYaml(root);

    CHX_LOG_INFO(CHX_LOG_ROOT()) << "after: " << g_person->getValue().toString() << " - " << g_person->toString();
    XX_PM(g_person_map, "class.map after");
    CHX_LOG_INFO(CHX_LOG_ROOT()) << "after: " << g_person_vec_map->toString();
}
#endif


static chx::Logger::ptr system_log = CHX_LOG_NAME("system");
static chx::Logger::ptr xx_log = CHX_LOG_NAME("xx");
void test_log() {
    xx_log->addAppender(chx::LogAppender::ptr(new chx::StdoutLogAppender));
    CHX_LOG_INFO(system_log) << "hello system" << std::endl;
    std::cout << chx::LoggerMgr::GetInstance()->toYamlString() << std::endl;

    YAML::Node root = YAML::LoadFile("/home/chx/Git/LogSystem/bin/conf/log.yml");
    chx::Config::LoadFromYaml(root);

    std::cout << "=============" << std::endl;
    std::cout << chx::LoggerMgr::GetInstance()->toYamlString() << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << root << std::endl;
    CHX_LOG_INFO(system_log) << "hello system" << std::endl;

    //system_log->setFormatter("%d - %m%n");
    //CHX_LOG_INFO(system_log) << "hello system" << std::endl;

    // std::cout << "=============" << std::endl;
    // std::cout << chx::LoggerMgr::GetInstance()->toYamlString() << std::endl;
    // std::cout << "=============" << std::endl;

    root = YAML::LoadFile("/home/chx/Git/LogSystem/bin/conf/log1.yml");
    chx::Config::LoadFromYaml(root);
    std::cout << "=============" << std::endl;
    std::cout << chx::LoggerMgr::GetInstance()->toYamlString() << std::endl;
    std::cout << "=============" << std::endl;

    // CHX_LOG_INFO(system_log) << system_log->getLevel();
}



int main(int argc, char** argv) {
    test_log();
    
    return 0;
}