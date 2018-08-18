//
// Generated file, do not edit! Created by nedtool 5.1 from Message/CrossLayerMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "CrossLayerMsg_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::CLType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::CLType"));
    e->insert(GENERAL, "GENERAL");
    e->insert(CROSS_LAYER_BASE, "CROSS_LAYER_BASE");
    e->insert(CROSS_LAYER_PHY, "CROSS_LAYER_PHY");
    e->insert(CROSS_LAYER_LINK, "CROSS_LAYER_LINK");
    e->insert(CROSS_LAYER_NET, "CROSS_LAYER_NET");
    e->insert(CROSS_LAYER_TRANS, "CROSS_LAYER_TRANS");
    e->insert(CROSS_LAYER_APP, "CROSS_LAYER_APP");
    e->insert(CROSS_LAYER_ENERGY, "CROSS_LAYER_ENERGY");
    e->insert(CROSS_LAYER_SELF, "CROSS_LAYER_SELF");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::NetType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::NetType"));
    e->insert(NET_GET_SELF, "NET_GET_SELF");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TransType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TransType"));
    e->insert(TRANS_GET_SELF, "TRANS_GET_SELF");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::LinkType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::LinkType"));
    e->insert(LINK_GET_SELF, "LINK_GET_SELF");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::PhyType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::PhyType"));
    e->insert(PHY_GET_SELF, "PHY_GET_SELF");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::AppType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::AppType"));
    e->insert(APP_GET_SELF, "APP_GET_SELF");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::CrossType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::CrossType"));
    e->insert(CHECK_TICK, "CHECK_TICK");
)

Register_Class(CrossLayerMsg)

CrossLayerMsg::CrossLayerMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = 0;
}

CrossLayerMsg::CrossLayerMsg(const CrossLayerMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

CrossLayerMsg::~CrossLayerMsg()
{
}

CrossLayerMsg& CrossLayerMsg::operator=(const CrossLayerMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void CrossLayerMsg::copy(const CrossLayerMsg& other)
{
    this->type = other.type;
    this->desc = other.desc;
}

void CrossLayerMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->desc);
}

void CrossLayerMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->desc);
}

int CrossLayerMsg::getType() const
{
    return this->type;
}

void CrossLayerMsg::setType(int type)
{
    this->type = type;
}

const char * CrossLayerMsg::getDesc() const
{
    return this->desc.c_str();
}

void CrossLayerMsg::setDesc(const char * desc)
{
    this->desc = desc;
}

class CrossLayerMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossLayerMsgDescriptor();
    virtual ~CrossLayerMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossLayerMsgDescriptor)

CrossLayerMsgDescriptor::CrossLayerMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossLayerMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

CrossLayerMsgDescriptor::~CrossLayerMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossLayerMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossLayerMsg *>(obj)!=nullptr;
}

const char **CrossLayerMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossLayerMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossLayerMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int CrossLayerMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *CrossLayerMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "desc",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int CrossLayerMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "desc")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossLayerMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossLayerMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossLayerMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::CLType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossLayerMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossLayerMsg *pp = (CrossLayerMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossLayerMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossLayerMsg *pp = (CrossLayerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossLayerMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossLayerMsg *pp = (CrossLayerMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::CLType");
        case 1: return oppstring2string(pp->getDesc());
        default: return "";
    }
}

bool CrossLayerMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossLayerMsg *pp = (CrossLayerMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::CLType)string2enum(value, "inet::CLType")); return true;
        case 1: pp->setDesc((value)); return true;
        default: return false;
    }
}

const char *CrossLayerMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossLayerMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossLayerMsg *pp = (CrossLayerMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CrossPhyMsg)

CrossPhyMsg::CrossPhyMsg(const char *name, short kind) : ::inet::CrossLayerMsg(name,kind)
{
    this->setType(CROSS_LAYER_PHY);
    this->setDesc("$$$ CROSS_LAYER_PHY generated by msg definition $$$");

    this->m_type = -1;
}

CrossPhyMsg::CrossPhyMsg(const CrossPhyMsg& other) : ::inet::CrossLayerMsg(other)
{
    copy(other);
}

CrossPhyMsg::~CrossPhyMsg()
{
}

CrossPhyMsg& CrossPhyMsg::operator=(const CrossPhyMsg& other)
{
    if (this==&other) return *this;
    ::inet::CrossLayerMsg::operator=(other);
    copy(other);
    return *this;
}

void CrossPhyMsg::copy(const CrossPhyMsg& other)
{
    this->m_type = other.m_type;
}

void CrossPhyMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::CrossLayerMsg::parsimPack(b);
    doParsimPacking(b,this->m_type);
}

void CrossPhyMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::CrossLayerMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->m_type);
}

int CrossPhyMsg::getM_type() const
{
    return this->m_type;
}

void CrossPhyMsg::setM_type(int m_type)
{
    this->m_type = m_type;
}

class CrossPhyMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossPhyMsgDescriptor();
    virtual ~CrossPhyMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossPhyMsgDescriptor)

CrossPhyMsgDescriptor::CrossPhyMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossPhyMsg", "inet::CrossLayerMsg")
{
    propertynames = nullptr;
}

CrossPhyMsgDescriptor::~CrossPhyMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossPhyMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossPhyMsg *>(obj)!=nullptr;
}

const char **CrossPhyMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossPhyMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossPhyMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CrossPhyMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CrossPhyMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "m_type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CrossPhyMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "m_type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossPhyMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossPhyMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossPhyMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::PhyType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossPhyMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossPhyMsg *pp = (CrossPhyMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossPhyMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossPhyMsg *pp = (CrossPhyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossPhyMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossPhyMsg *pp = (CrossPhyMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getM_type(), "inet::PhyType");
        default: return "";
    }
}

bool CrossPhyMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossPhyMsg *pp = (CrossPhyMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setM_type((inet::PhyType)string2enum(value, "inet::PhyType")); return true;
        default: return false;
    }
}

const char *CrossPhyMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossPhyMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossPhyMsg *pp = (CrossPhyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CrossLinkMsg)

CrossLinkMsg::CrossLinkMsg(const char *name, short kind) : ::inet::CrossLayerMsg(name,kind)
{
    this->setType(CROSS_LAYER_LINK);
    this->setDesc("$$$ CROSS_LAYER_LINK generated by msg definition $$$");

    this->m_type = -1;
}

CrossLinkMsg::CrossLinkMsg(const CrossLinkMsg& other) : ::inet::CrossLayerMsg(other)
{
    copy(other);
}

CrossLinkMsg::~CrossLinkMsg()
{
}

CrossLinkMsg& CrossLinkMsg::operator=(const CrossLinkMsg& other)
{
    if (this==&other) return *this;
    ::inet::CrossLayerMsg::operator=(other);
    copy(other);
    return *this;
}

void CrossLinkMsg::copy(const CrossLinkMsg& other)
{
    this->m_type = other.m_type;
}

void CrossLinkMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::CrossLayerMsg::parsimPack(b);
    doParsimPacking(b,this->m_type);
}

void CrossLinkMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::CrossLayerMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->m_type);
}

int CrossLinkMsg::getM_type() const
{
    return this->m_type;
}

void CrossLinkMsg::setM_type(int m_type)
{
    this->m_type = m_type;
}

class CrossLinkMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossLinkMsgDescriptor();
    virtual ~CrossLinkMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossLinkMsgDescriptor)

CrossLinkMsgDescriptor::CrossLinkMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossLinkMsg", "inet::CrossLayerMsg")
{
    propertynames = nullptr;
}

CrossLinkMsgDescriptor::~CrossLinkMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossLinkMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossLinkMsg *>(obj)!=nullptr;
}

const char **CrossLinkMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossLinkMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossLinkMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CrossLinkMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CrossLinkMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "m_type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CrossLinkMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "m_type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossLinkMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossLinkMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossLinkMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::LinkType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossLinkMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossLinkMsg *pp = (CrossLinkMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossLinkMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossLinkMsg *pp = (CrossLinkMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossLinkMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossLinkMsg *pp = (CrossLinkMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getM_type(), "inet::LinkType");
        default: return "";
    }
}

bool CrossLinkMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossLinkMsg *pp = (CrossLinkMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setM_type((inet::LinkType)string2enum(value, "inet::LinkType")); return true;
        default: return false;
    }
}

const char *CrossLinkMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossLinkMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossLinkMsg *pp = (CrossLinkMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CrossNetMsg)

CrossNetMsg::CrossNetMsg(const char *name, short kind) : ::inet::CrossLayerMsg(name,kind)
{
    this->setType(CROSS_LAYER_NET);
    this->setDesc("$$$ CROSS_LAYER_NET generated by msg definition $$$");

    this->m_type = -1;
}

CrossNetMsg::CrossNetMsg(const CrossNetMsg& other) : ::inet::CrossLayerMsg(other)
{
    copy(other);
}

CrossNetMsg::~CrossNetMsg()
{
}

CrossNetMsg& CrossNetMsg::operator=(const CrossNetMsg& other)
{
    if (this==&other) return *this;
    ::inet::CrossLayerMsg::operator=(other);
    copy(other);
    return *this;
}

void CrossNetMsg::copy(const CrossNetMsg& other)
{
    this->m_type = other.m_type;
}

void CrossNetMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::CrossLayerMsg::parsimPack(b);
    doParsimPacking(b,this->m_type);
}

void CrossNetMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::CrossLayerMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->m_type);
}

int CrossNetMsg::getM_type() const
{
    return this->m_type;
}

void CrossNetMsg::setM_type(int m_type)
{
    this->m_type = m_type;
}

class CrossNetMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossNetMsgDescriptor();
    virtual ~CrossNetMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossNetMsgDescriptor)

CrossNetMsgDescriptor::CrossNetMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossNetMsg", "inet::CrossLayerMsg")
{
    propertynames = nullptr;
}

CrossNetMsgDescriptor::~CrossNetMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossNetMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossNetMsg *>(obj)!=nullptr;
}

const char **CrossNetMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossNetMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossNetMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CrossNetMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CrossNetMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "m_type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CrossNetMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "m_type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossNetMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossNetMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossNetMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::NetType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossNetMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossNetMsg *pp = (CrossNetMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossNetMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossNetMsg *pp = (CrossNetMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossNetMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossNetMsg *pp = (CrossNetMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getM_type(), "inet::NetType");
        default: return "";
    }
}

bool CrossNetMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossNetMsg *pp = (CrossNetMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setM_type((inet::NetType)string2enum(value, "inet::NetType")); return true;
        default: return false;
    }
}

const char *CrossNetMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossNetMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossNetMsg *pp = (CrossNetMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CrossTransMsg)

CrossTransMsg::CrossTransMsg(const char *name, short kind) : ::inet::CrossLayerMsg(name,kind)
{
    this->setType(CROSS_LAYER_TRANS);
    this->setDesc("$$$ CROSS_LAYER_TRANS generated by msg definition $$$");

    this->m_type = -1;
}

CrossTransMsg::CrossTransMsg(const CrossTransMsg& other) : ::inet::CrossLayerMsg(other)
{
    copy(other);
}

CrossTransMsg::~CrossTransMsg()
{
}

CrossTransMsg& CrossTransMsg::operator=(const CrossTransMsg& other)
{
    if (this==&other) return *this;
    ::inet::CrossLayerMsg::operator=(other);
    copy(other);
    return *this;
}

void CrossTransMsg::copy(const CrossTransMsg& other)
{
    this->m_type = other.m_type;
}

void CrossTransMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::CrossLayerMsg::parsimPack(b);
    doParsimPacking(b,this->m_type);
}

void CrossTransMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::CrossLayerMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->m_type);
}

int CrossTransMsg::getM_type() const
{
    return this->m_type;
}

void CrossTransMsg::setM_type(int m_type)
{
    this->m_type = m_type;
}

class CrossTransMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossTransMsgDescriptor();
    virtual ~CrossTransMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossTransMsgDescriptor)

CrossTransMsgDescriptor::CrossTransMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossTransMsg", "inet::CrossLayerMsg")
{
    propertynames = nullptr;
}

CrossTransMsgDescriptor::~CrossTransMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossTransMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossTransMsg *>(obj)!=nullptr;
}

const char **CrossTransMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossTransMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossTransMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CrossTransMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CrossTransMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "m_type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CrossTransMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "m_type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossTransMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossTransMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossTransMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::TransType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossTransMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossTransMsg *pp = (CrossTransMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossTransMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossTransMsg *pp = (CrossTransMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossTransMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossTransMsg *pp = (CrossTransMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getM_type(), "inet::TransType");
        default: return "";
    }
}

bool CrossTransMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossTransMsg *pp = (CrossTransMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setM_type((inet::TransType)string2enum(value, "inet::TransType")); return true;
        default: return false;
    }
}

const char *CrossTransMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossTransMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossTransMsg *pp = (CrossTransMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CrossAppMsg)

CrossAppMsg::CrossAppMsg(const char *name, short kind) : ::inet::CrossLayerMsg(name,kind)
{
    this->setType(CROSS_LAYER_APP);
    this->setDesc("$$$ CROSS_LAYER_APP generated by msg definition $$$");

    this->m_type = -1;
}

CrossAppMsg::CrossAppMsg(const CrossAppMsg& other) : ::inet::CrossLayerMsg(other)
{
    copy(other);
}

CrossAppMsg::~CrossAppMsg()
{
}

CrossAppMsg& CrossAppMsg::operator=(const CrossAppMsg& other)
{
    if (this==&other) return *this;
    ::inet::CrossLayerMsg::operator=(other);
    copy(other);
    return *this;
}

void CrossAppMsg::copy(const CrossAppMsg& other)
{
    this->m_type = other.m_type;
}

void CrossAppMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::CrossLayerMsg::parsimPack(b);
    doParsimPacking(b,this->m_type);
}

void CrossAppMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::CrossLayerMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->m_type);
}

int CrossAppMsg::getM_type() const
{
    return this->m_type;
}

void CrossAppMsg::setM_type(int m_type)
{
    this->m_type = m_type;
}

class CrossAppMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossAppMsgDescriptor();
    virtual ~CrossAppMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossAppMsgDescriptor)

CrossAppMsgDescriptor::CrossAppMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossAppMsg", "inet::CrossLayerMsg")
{
    propertynames = nullptr;
}

CrossAppMsgDescriptor::~CrossAppMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossAppMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossAppMsg *>(obj)!=nullptr;
}

const char **CrossAppMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossAppMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossAppMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CrossAppMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CrossAppMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "m_type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CrossAppMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "m_type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossAppMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossAppMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossAppMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::AppType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossAppMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossAppMsg *pp = (CrossAppMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossAppMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossAppMsg *pp = (CrossAppMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossAppMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossAppMsg *pp = (CrossAppMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getM_type(), "inet::AppType");
        default: return "";
    }
}

bool CrossAppMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossAppMsg *pp = (CrossAppMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setM_type((inet::AppType)string2enum(value, "inet::AppType")); return true;
        default: return false;
    }
}

const char *CrossAppMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossAppMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossAppMsg *pp = (CrossAppMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(CrossSelfMsg)

CrossSelfMsg::CrossSelfMsg(const char *name, short kind) : ::inet::CrossLayerMsg(name,kind)
{
    this->setType(CROSS_LAYER_SELF);
    this->setDesc("$$$ CROSS_LAYER_SELF generated by msg definition $$$");

    this->m_type = -1;
}

CrossSelfMsg::CrossSelfMsg(const CrossSelfMsg& other) : ::inet::CrossLayerMsg(other)
{
    copy(other);
}

CrossSelfMsg::~CrossSelfMsg()
{
}

CrossSelfMsg& CrossSelfMsg::operator=(const CrossSelfMsg& other)
{
    if (this==&other) return *this;
    ::inet::CrossLayerMsg::operator=(other);
    copy(other);
    return *this;
}

void CrossSelfMsg::copy(const CrossSelfMsg& other)
{
    this->m_type = other.m_type;
}

void CrossSelfMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::CrossLayerMsg::parsimPack(b);
    doParsimPacking(b,this->m_type);
}

void CrossSelfMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::CrossLayerMsg::parsimUnpack(b);
    doParsimUnpacking(b,this->m_type);
}

int CrossSelfMsg::getM_type() const
{
    return this->m_type;
}

void CrossSelfMsg::setM_type(int m_type)
{
    this->m_type = m_type;
}

class CrossSelfMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    CrossSelfMsgDescriptor();
    virtual ~CrossSelfMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(CrossSelfMsgDescriptor)

CrossSelfMsgDescriptor::CrossSelfMsgDescriptor() : omnetpp::cClassDescriptor("inet::CrossSelfMsg", "inet::CrossLayerMsg")
{
    propertynames = nullptr;
}

CrossSelfMsgDescriptor::~CrossSelfMsgDescriptor()
{
    delete[] propertynames;
}

bool CrossSelfMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CrossSelfMsg *>(obj)!=nullptr;
}

const char **CrossSelfMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *CrossSelfMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int CrossSelfMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int CrossSelfMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *CrossSelfMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "m_type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int CrossSelfMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "m_type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *CrossSelfMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **CrossSelfMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CrossSelfMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::CrossType";
            return nullptr;
        default: return nullptr;
    }
}

int CrossSelfMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    CrossSelfMsg *pp = (CrossSelfMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *CrossSelfMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossSelfMsg *pp = (CrossSelfMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CrossSelfMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    CrossSelfMsg *pp = (CrossSelfMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getM_type(), "inet::CrossType");
        default: return "";
    }
}

bool CrossSelfMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    CrossSelfMsg *pp = (CrossSelfMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setM_type((inet::CrossType)string2enum(value, "inet::CrossType")); return true;
        default: return false;
    }
}

const char *CrossSelfMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *CrossSelfMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    CrossSelfMsg *pp = (CrossSelfMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

