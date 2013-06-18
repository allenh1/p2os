<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en-US">
<head>
<link rel="icon" href="/robotmodel/robot_model/static/hgicon.png" type="image/png" />
<meta name="robots" content="index, nofollow" />
<link rel="stylesheet" href="/robotmodel/robot_model/static/style-paper.css" type="text/css" />

<title>robotmodel-robot_model: d33189ce4a62 collada_urdf/src/collada_urdf.cpp</title>
<style type="text/css">
div.kforgenav {
position: relative;
top: 0;
bottom: 0;
height: 20px;
z-index: 1000;
width: 100%;
}

.kforgenav ul {
padding: 0;
margin: 0;
list-style: none;
line-height: 1;
cursor: pointer;
height: auto;
}

.kforgenav li {
padding: 0;
margin: 0;
list-style: none;
float: left;
position: relative;
text-align: left;
}

.kforgenav a {
display: block;
padding: 4px 15px 3px;
text-decoration: none;
font-size: 11px;
color: #000;
border: 0;
background: #fff;
}
</style></head>
<body><div class="kforgenav"><ul><li><a href="/">kforge.ros.org</a></li><li><a href="/people/home/">Profile</a></li><li><a href="/projects/">Projects</a></li><li><a href="/projects/robotmodel/">Robot Model</a></li><li><a href="/projects/robotmodel/services/">Services</a></li><li><a href="/projects/robotmodel/members/">Members</a></li></ul></div>

<div class="container">
<div class="menu">
<div class="logo">
<a href="http://mercurial.selenic.com/">
<img src="/robotmodel/robot_model/static/hglogo.png" alt="mercurial" /></a>
</div>
<ul>
<li><a href="/robotmodel/robot_model/shortlog/d33189ce4a62">log</a></li>
<li><a href="/robotmodel/robot_model/graph/d33189ce4a62">graph</a></li>
<li><a href="/robotmodel/robot_model/tags">tags</a></li>
<li><a href="/robotmodel/robot_model/branches">branches</a></li>
</ul>
<ul>
<li><a href="/robotmodel/robot_model/rev/d33189ce4a62">changeset</a></li>
<li><a href="/robotmodel/robot_model/file/d33189ce4a62/collada_urdf/src/">browse</a></li>
</ul>
<ul>
<li class="active">file</li>
<li><a href="/robotmodel/robot_model/file/tip/collada_urdf/src/collada_urdf.cpp">latest</a></li>
<li><a href="/robotmodel/robot_model/diff/d33189ce4a62/collada_urdf/src/collada_urdf.cpp">diff</a></li>
<li><a href="/robotmodel/robot_model/annotate/d33189ce4a62/collada_urdf/src/collada_urdf.cpp">annotate</a></li>
<li><a href="/robotmodel/robot_model/log/d33189ce4a62/collada_urdf/src/collada_urdf.cpp">file log</a></li>
<li><a href="/robotmodel/robot_model/raw-file/d33189ce4a62/collada_urdf/src/collada_urdf.cpp">raw</a></li>
</ul>
</div>

<div class="main">
<h2><a href="/robotmodel/robot_model/">robotmodel-robot_model</a></h2>
<h3>view collada_urdf/src/collada_urdf.cpp @ 291:d33189ce4a62</h3>

<form class="search" action="/robotmodel/robot_model/log">

<p><input name="rev" id="search1" type="text" size="30" /></p>
<div id="hint">find changesets by author, revision,
files, or words in the commit message</div>
</form>

<div class="description">fix multiple visuals.</div>

<table id="changesetEntry">
<tr>
 <th class="author">author</th>
 <td class="author">&#74;&#111;&#104;&#110;&#32;&#72;&#115;&#117;&#32;&#60;&#106;&#111;&#104;&#110;&#104;&#115;&#117;&#64;&#119;&#105;&#108;&#108;&#111;&#119;&#103;&#97;&#114;&#97;&#103;&#101;&#46;&#99;&#111;&#109;&#62;</td>
</tr>
<tr>
 <th class="date">date</th>
 <td class="date">Wed Mar 16 20:52:57 2011 -0700 (2011-03-16)</td>
</tr>
<tr>
 <th class="author">parents</th>
 <td class="author"><a href="/robotmodel/robot_model/file/ba3671034cdb/collada_urdf/src/collada_urdf.cpp">ba3671034cdb</a> </td>
</tr>
<tr>
 <th class="author">children</th>
 <td class="author"><a href="/robotmodel/robot_model/file/4986ba77eafd/collada_urdf/src/collada_urdf.cpp">4986ba77eafd</a> </td>
</tr>

</table>

<div class="overflow">
<div class="sourcefirst"> line source</div>

<div class="parity0 source"><a href="#l1" id="l1">     1</a> /*********************************************************************
</div>
<div class="parity1 source"><a href="#l2" id="l2">     2</a> * Software License Agreement (BSD License)
</div>
<div class="parity0 source"><a href="#l3" id="l3">     3</a> * 
</div>
<div class="parity1 source"><a href="#l4" id="l4">     4</a> *  Copyright (c) 2010, Willow Garage, Inc., University of Tokyo
</div>
<div class="parity0 source"><a href="#l5" id="l5">     5</a> *  All rights reserved.
</div>
<div class="parity1 source"><a href="#l6" id="l6">     6</a> * 
</div>
<div class="parity0 source"><a href="#l7" id="l7">     7</a> *  Redistribution and use in source and binary forms, with or without
</div>
<div class="parity1 source"><a href="#l8" id="l8">     8</a> *  modification, are permitted provided that the following conditions
</div>
<div class="parity0 source"><a href="#l9" id="l9">     9</a> *  are met:
</div>
<div class="parity1 source"><a href="#l10" id="l10">    10</a> * 
</div>
<div class="parity0 source"><a href="#l11" id="l11">    11</a> *   * Redstributions of source code must retain the above copyright
</div>
<div class="parity1 source"><a href="#l12" id="l12">    12</a> *     notice, this list of conditions and the following disclaimer.
</div>
<div class="parity0 source"><a href="#l13" id="l13">    13</a> *   * Redistributions in binary form must reproduce the above
</div>
<div class="parity1 source"><a href="#l14" id="l14">    14</a> *     copyright notice, this list of conditions and the following
</div>
<div class="parity0 source"><a href="#l15" id="l15">    15</a> *     disclaimer in the documentation and/or other materials provided
</div>
<div class="parity1 source"><a href="#l16" id="l16">    16</a> *     with the distribution.
</div>
<div class="parity0 source"><a href="#l17" id="l17">    17</a> *   * Neither the name of the Willow Garage nor the names of its
</div>
<div class="parity1 source"><a href="#l18" id="l18">    18</a> *     contributors may be used to endorse or promote products derived
</div>
<div class="parity0 source"><a href="#l19" id="l19">    19</a> *     from this software without specific prior written permission.
</div>
<div class="parity1 source"><a href="#l20" id="l20">    20</a> * 
</div>
<div class="parity0 source"><a href="#l21" id="l21">    21</a> *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
</div>
<div class="parity1 source"><a href="#l22" id="l22">    22</a> *  &quot;AS IS&quot; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
</div>
<div class="parity0 source"><a href="#l23" id="l23">    23</a> *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
</div>
<div class="parity1 source"><a href="#l24" id="l24">    24</a> *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
</div>
<div class="parity0 source"><a href="#l25" id="l25">    25</a> *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
</div>
<div class="parity1 source"><a href="#l26" id="l26">    26</a> *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
</div>
<div class="parity0 source"><a href="#l27" id="l27">    27</a> *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
</div>
<div class="parity1 source"><a href="#l28" id="l28">    28</a> *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
</div>
<div class="parity0 source"><a href="#l29" id="l29">    29</a> *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
</div>
<div class="parity1 source"><a href="#l30" id="l30">    30</a> *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
</div>
<div class="parity0 source"><a href="#l31" id="l31">    31</a> *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
</div>
<div class="parity1 source"><a href="#l32" id="l32">    32</a> *  POSSIBILITY OF SUCH DAMAGE.
</div>
<div class="parity0 source"><a href="#l33" id="l33">    33</a> *********************************************************************/
</div>
<div class="parity1 source"><a href="#l34" id="l34">    34</a> 
</div>
<div class="parity0 source"><a href="#l35" id="l35">    35</a> /* Authors: Rosen Diankov, Tim Field */
</div>
<div class="parity1 source"><a href="#l36" id="l36">    36</a> 
</div>
<div class="parity0 source"><a href="#l37" id="l37">    37</a> #include &quot;collada_urdf/collada_urdf.h&quot;
</div>
<div class="parity1 source"><a href="#l38" id="l38">    38</a> #include &lt;map&gt;
</div>
<div class="parity0 source"><a href="#l39" id="l39">    39</a> #include &lt;vector&gt;
</div>
<div class="parity1 source"><a href="#l40" id="l40">    40</a> #include &lt;list&gt;
</div>
<div class="parity0 source"><a href="#l41" id="l41">    41</a> 
</div>
<div class="parity1 source"><a href="#l42" id="l42">    42</a> #include &lt;dae.h&gt;
</div>
<div class="parity0 source"><a href="#l43" id="l43">    43</a> #include &lt;dae/daeDocument.h&gt;
</div>
<div class="parity1 source"><a href="#l44" id="l44">    44</a> #include &lt;dae/daeErrorHandler.h&gt;
</div>
<div class="parity0 source"><a href="#l45" id="l45">    45</a> #include &lt;dae/domAny.h&gt;
</div>
<div class="parity1 source"><a href="#l46" id="l46">    46</a> #include &lt;dom/domCOLLADA.h&gt;
</div>
<div class="parity0 source"><a href="#l47" id="l47">    47</a> #include &lt;dom/domConstants.h&gt;
</div>
<div class="parity1 source"><a href="#l48" id="l48">    48</a> #include &lt;dom/domElements.h&gt;
</div>
<div class="parity0 source"><a href="#l49" id="l49">    49</a> #include &lt;dom/domTriangles.h&gt;
</div>
<div class="parity1 source"><a href="#l50" id="l50">    50</a> #include &lt;dom/domTypes.h&gt;
</div>
<div class="parity0 source"><a href="#l51" id="l51">    51</a> #include &lt;resource_retriever/retriever.h&gt;
</div>
<div class="parity1 source"><a href="#l52" id="l52">    52</a> #include &lt;urdf/model.h&gt;
</div>
<div class="parity0 source"><a href="#l53" id="l53">    53</a> #include &lt;urdf/pose.h&gt;
</div>
<div class="parity1 source"><a href="#l54" id="l54">    54</a> #include &lt;angles/angles.h&gt;
</div>
<div class="parity0 source"><a href="#l55" id="l55">    55</a> 
</div>
<div class="parity1 source"><a href="#l56" id="l56">    56</a> #include &lt;boost/date_time/posix_time/posix_time.hpp&gt;
</div>
<div class="parity0 source"><a href="#l57" id="l57">    57</a> #include &lt;boost/date_time/posix_time/posix_time_io.hpp&gt;
</div>
<div class="parity1 source"><a href="#l58" id="l58">    58</a> #include &lt;boost/format.hpp&gt;
</div>
<div class="parity0 source"><a href="#l59" id="l59">    59</a> 
</div>
<div class="parity1 source"><a href="#l60" id="l60">    60</a> #include &lt;assimp/assimp.hpp&gt;
</div>
<div class="parity0 source"><a href="#l61" id="l61">    61</a> #include &lt;assimp/aiScene.h&gt;
</div>
<div class="parity1 source"><a href="#l62" id="l62">    62</a> #include &lt;assimp/aiPostProcess.h&gt;
</div>
<div class="parity0 source"><a href="#l63" id="l63">    63</a> #include &lt;assimp/IOStream.h&gt;
</div>
<div class="parity1 source"><a href="#l64" id="l64">    64</a> #include &lt;assimp/IOSystem.h&gt;
</div>
<div class="parity0 source"><a href="#l65" id="l65">    65</a> 
</div>
<div class="parity1 source"><a href="#l66" id="l66">    66</a> #define FOREACH(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); (it)++)
</div>
<div class="parity0 source"><a href="#l67" id="l67">    67</a> #define FOREACHC FOREACH
</div>
<div class="parity1 source"><a href="#l68" id="l68">    68</a> 
</div>
<div class="parity0 source"><a href="#l69" id="l69">    69</a> using namespace std;
</div>
<div class="parity1 source"><a href="#l70" id="l70">    70</a> 
</div>
<div class="parity0 source"><a href="#l71" id="l71">    71</a> namespace collada_urdf {
</div>
<div class="parity1 source"><a href="#l72" id="l72">    72</a> 
</div>
<div class="parity0 source"><a href="#l73" id="l73">    73</a> /// ResourceIOStream is copied from rviz (BSD, Willow Garage)
</div>
<div class="parity1 source"><a href="#l74" id="l74">    74</a> class ResourceIOStream : public Assimp::IOStream
</div>
<div class="parity0 source"><a href="#l75" id="l75">    75</a> {
</div>
<div class="parity1 source"><a href="#l76" id="l76">    76</a> public:
</div>
<div class="parity0 source"><a href="#l77" id="l77">    77</a>     ResourceIOStream(const resource_retriever::MemoryResource&amp; res)
</div>
<div class="parity1 source"><a href="#l78" id="l78">    78</a>         : res_(res)
</div>
<div class="parity0 source"><a href="#l79" id="l79">    79</a>         , pos_(res.data.get())
</div>
<div class="parity1 source"><a href="#l80" id="l80">    80</a>     {}
</div>
<div class="parity0 source"><a href="#l81" id="l81">    81</a> 
</div>
<div class="parity1 source"><a href="#l82" id="l82">    82</a>     ~ResourceIOStream()
</div>
<div class="parity0 source"><a href="#l83" id="l83">    83</a>     {}
</div>
<div class="parity1 source"><a href="#l84" id="l84">    84</a> 
</div>
<div class="parity0 source"><a href="#l85" id="l85">    85</a>     size_t Read(void* buffer, size_t size, size_t count)
</div>
<div class="parity1 source"><a href="#l86" id="l86">    86</a>     {
</div>
<div class="parity0 source"><a href="#l87" id="l87">    87</a>         size_t to_read = size * count;
</div>
<div class="parity1 source"><a href="#l88" id="l88">    88</a>         if (pos_ + to_read &gt; res_.data.get() + res_.size)
</div>
<div class="parity0 source"><a href="#l89" id="l89">    89</a>             {
</div>
<div class="parity1 source"><a href="#l90" id="l90">    90</a>                 to_read = res_.size - (pos_ - res_.data.get());
</div>
<div class="parity0 source"><a href="#l91" id="l91">    91</a>             }
</div>
<div class="parity1 source"><a href="#l92" id="l92">    92</a> 
</div>
<div class="parity0 source"><a href="#l93" id="l93">    93</a>         memcpy(buffer, pos_, to_read);
</div>
<div class="parity1 source"><a href="#l94" id="l94">    94</a>         pos_ += to_read;
</div>
<div class="parity0 source"><a href="#l95" id="l95">    95</a> 
</div>
<div class="parity1 source"><a href="#l96" id="l96">    96</a>         return to_read;
</div>
<div class="parity0 source"><a href="#l97" id="l97">    97</a>     }
</div>
<div class="parity1 source"><a href="#l98" id="l98">    98</a> 
</div>
<div class="parity0 source"><a href="#l99" id="l99">    99</a>     size_t Write( const void* buffer, size_t size, size_t count) { ROS_BREAK(); return 0; }
</div>
<div class="parity1 source"><a href="#l100" id="l100">   100</a> 
</div>
<div class="parity0 source"><a href="#l101" id="l101">   101</a>     aiReturn Seek( size_t offset, aiOrigin origin)
</div>
<div class="parity1 source"><a href="#l102" id="l102">   102</a>     {
</div>
<div class="parity0 source"><a href="#l103" id="l103">   103</a>         uint8_t* new_pos = 0;
</div>
<div class="parity1 source"><a href="#l104" id="l104">   104</a>         switch (origin)
</div>
<div class="parity0 source"><a href="#l105" id="l105">   105</a>             {
</div>
<div class="parity1 source"><a href="#l106" id="l106">   106</a>             case aiOrigin_SET:
</div>
<div class="parity0 source"><a href="#l107" id="l107">   107</a>                 new_pos = res_.data.get() + offset;
</div>
<div class="parity1 source"><a href="#l108" id="l108">   108</a>                 break;
</div>
<div class="parity0 source"><a href="#l109" id="l109">   109</a>             case aiOrigin_CUR:
</div>
<div class="parity1 source"><a href="#l110" id="l110">   110</a>                 new_pos = pos_ + offset; // TODO is this right?  can offset really not be negative
</div>
<div class="parity0 source"><a href="#l111" id="l111">   111</a>                 break;
</div>
<div class="parity1 source"><a href="#l112" id="l112">   112</a>             case aiOrigin_END:
</div>
<div class="parity0 source"><a href="#l113" id="l113">   113</a>                 new_pos = res_.data.get() + res_.size - offset; // TODO is this right?
</div>
<div class="parity1 source"><a href="#l114" id="l114">   114</a>                 break;
</div>
<div class="parity0 source"><a href="#l115" id="l115">   115</a>             default:
</div>
<div class="parity1 source"><a href="#l116" id="l116">   116</a>                 ROS_BREAK();
</div>
<div class="parity0 source"><a href="#l117" id="l117">   117</a>             }
</div>
<div class="parity1 source"><a href="#l118" id="l118">   118</a> 
</div>
<div class="parity0 source"><a href="#l119" id="l119">   119</a>         if (new_pos &lt; res_.data.get() || new_pos &gt; res_.data.get() + res_.size)
</div>
<div class="parity1 source"><a href="#l120" id="l120">   120</a>             {
</div>
<div class="parity0 source"><a href="#l121" id="l121">   121</a>                 return aiReturn_FAILURE;
</div>
<div class="parity1 source"><a href="#l122" id="l122">   122</a>             }
</div>
<div class="parity0 source"><a href="#l123" id="l123">   123</a> 
</div>
<div class="parity1 source"><a href="#l124" id="l124">   124</a>         pos_ = new_pos;
</div>
<div class="parity0 source"><a href="#l125" id="l125">   125</a>         return aiReturn_SUCCESS;
</div>
<div class="parity1 source"><a href="#l126" id="l126">   126</a>     }
</div>
<div class="parity0 source"><a href="#l127" id="l127">   127</a> 
</div>
<div class="parity1 source"><a href="#l128" id="l128">   128</a>     size_t Tell() const
</div>
<div class="parity0 source"><a href="#l129" id="l129">   129</a>     {
</div>
<div class="parity1 source"><a href="#l130" id="l130">   130</a>         return pos_ - res_.data.get();
</div>
<div class="parity0 source"><a href="#l131" id="l131">   131</a>     }
</div>
<div class="parity1 source"><a href="#l132" id="l132">   132</a> 
</div>
<div class="parity0 source"><a href="#l133" id="l133">   133</a>     size_t FileSize() const
</div>
<div class="parity1 source"><a href="#l134" id="l134">   134</a>     {
</div>
<div class="parity0 source"><a href="#l135" id="l135">   135</a>         return res_.size;
</div>
<div class="parity1 source"><a href="#l136" id="l136">   136</a>     }
</div>
<div class="parity0 source"><a href="#l137" id="l137">   137</a> 
</div>
<div class="parity1 source"><a href="#l138" id="l138">   138</a>     void Flush() {}
</div>
<div class="parity0 source"><a href="#l139" id="l139">   139</a> 
</div>
<div class="parity1 source"><a href="#l140" id="l140">   140</a> private:
</div>
<div class="parity0 source"><a href="#l141" id="l141">   141</a>     resource_retriever::MemoryResource res_;
</div>
<div class="parity1 source"><a href="#l142" id="l142">   142</a>     uint8_t* pos_;
</div>
<div class="parity0 source"><a href="#l143" id="l143">   143</a> };
</div>
<div class="parity1 source"><a href="#l144" id="l144">   144</a> 
</div>
<div class="parity0 source"><a href="#l145" id="l145">   145</a> /// ResourceIOSystem is copied from rviz (BSD, Willow Garage)
</div>
<div class="parity1 source"><a href="#l146" id="l146">   146</a> class ResourceIOSystem : public Assimp::IOSystem
</div>
<div class="parity0 source"><a href="#l147" id="l147">   147</a> {
</div>
<div class="parity1 source"><a href="#l148" id="l148">   148</a> public:
</div>
<div class="parity0 source"><a href="#l149" id="l149">   149</a>     ResourceIOSystem()
</div>
<div class="parity1 source"><a href="#l150" id="l150">   150</a>     {
</div>
<div class="parity0 source"><a href="#l151" id="l151">   151</a>     }
</div>
<div class="parity1 source"><a href="#l152" id="l152">   152</a> 
</div>
<div class="parity0 source"><a href="#l153" id="l153">   153</a>     ~ResourceIOSystem()
</div>
<div class="parity1 source"><a href="#l154" id="l154">   154</a>     {
</div>
<div class="parity0 source"><a href="#l155" id="l155">   155</a>     }
</div>
<div class="parity1 source"><a href="#l156" id="l156">   156</a> 
</div>
<div class="parity0 source"><a href="#l157" id="l157">   157</a>     // Check whether a specific file exists
</div>
<div class="parity1 source"><a href="#l158" id="l158">   158</a>     bool Exists(const char* file) const
</div>
<div class="parity0 source"><a href="#l159" id="l159">   159</a>     {
</div>
<div class="parity1 source"><a href="#l160" id="l160">   160</a>         // Ugly -- two retrievals where there should be one (Exists + Open)
</div>
<div class="parity0 source"><a href="#l161" id="l161">   161</a>         // resource_retriever needs a way of checking for existence
</div>
<div class="parity1 source"><a href="#l162" id="l162">   162</a>         // TODO: cache this
</div>
<div class="parity0 source"><a href="#l163" id="l163">   163</a>         resource_retriever::MemoryResource res;
</div>
<div class="parity1 source"><a href="#l164" id="l164">   164</a>         try {
</div>
<div class="parity0 source"><a href="#l165" id="l165">   165</a>             res = retriever_.get(file);
</div>
<div class="parity1 source"><a href="#l166" id="l166">   166</a>         }
</div>
<div class="parity0 source"><a href="#l167" id="l167">   167</a>         catch (resource_retriever::Exception&amp; e) {
</div>
<div class="parity1 source"><a href="#l168" id="l168">   168</a>             return false;
</div>
<div class="parity0 source"><a href="#l169" id="l169">   169</a>         }
</div>
<div class="parity1 source"><a href="#l170" id="l170">   170</a> 
</div>
<div class="parity0 source"><a href="#l171" id="l171">   171</a>         return true;
</div>
<div class="parity1 source"><a href="#l172" id="l172">   172</a>     }
</div>
<div class="parity0 source"><a href="#l173" id="l173">   173</a> 
</div>
<div class="parity1 source"><a href="#l174" id="l174">   174</a>     // Get the path delimiter character we'd like to see
</div>
<div class="parity0 source"><a href="#l175" id="l175">   175</a>     char getOsSeparator() const
</div>
<div class="parity1 source"><a href="#l176" id="l176">   176</a>     {
</div>
<div class="parity0 source"><a href="#l177" id="l177">   177</a>         return '/';
</div>
<div class="parity1 source"><a href="#l178" id="l178">   178</a>     }
</div>
<div class="parity0 source"><a href="#l179" id="l179">   179</a> 
</div>
<div class="parity1 source"><a href="#l180" id="l180">   180</a>     // ... and finally a method to open a custom stream
</div>
<div class="parity0 source"><a href="#l181" id="l181">   181</a>     Assimp::IOStream* Open(const char* file, const char* mode)
</div>
<div class="parity1 source"><a href="#l182" id="l182">   182</a>     {
</div>
<div class="parity0 source"><a href="#l183" id="l183">   183</a>         ROS_ASSERT(mode == std::string(&quot;r&quot;) || mode == std::string(&quot;rb&quot;));
</div>
<div class="parity1 source"><a href="#l184" id="l184">   184</a> 
</div>
<div class="parity0 source"><a href="#l185" id="l185">   185</a>         // Ugly -- two retrievals where there should be one (Exists + Open)
</div>
<div class="parity1 source"><a href="#l186" id="l186">   186</a>         // resource_retriever needs a way of checking for existence
</div>
<div class="parity0 source"><a href="#l187" id="l187">   187</a>         resource_retriever::MemoryResource res;
</div>
<div class="parity1 source"><a href="#l188" id="l188">   188</a>         try {
</div>
<div class="parity0 source"><a href="#l189" id="l189">   189</a>             res = retriever_.get(file);
</div>
<div class="parity1 source"><a href="#l190" id="l190">   190</a>         }
</div>
<div class="parity0 source"><a href="#l191" id="l191">   191</a>         catch (resource_retriever::Exception&amp; e) {
</div>
<div class="parity1 source"><a href="#l192" id="l192">   192</a>             return 0;
</div>
<div class="parity0 source"><a href="#l193" id="l193">   193</a>         }
</div>
<div class="parity1 source"><a href="#l194" id="l194">   194</a> 
</div>
<div class="parity0 source"><a href="#l195" id="l195">   195</a>         return new ResourceIOStream(res);
</div>
<div class="parity1 source"><a href="#l196" id="l196">   196</a>     }
</div>
<div class="parity0 source"><a href="#l197" id="l197">   197</a> 
</div>
<div class="parity1 source"><a href="#l198" id="l198">   198</a>     void Close(Assimp::IOStream* stream) { delete stream; }
</div>
<div class="parity0 source"><a href="#l199" id="l199">   199</a> 
</div>
<div class="parity1 source"><a href="#l200" id="l200">   200</a> private:
</div>
<div class="parity0 source"><a href="#l201" id="l201">   201</a>     mutable resource_retriever::Retriever retriever_;
</div>
<div class="parity1 source"><a href="#l202" id="l202">   202</a> };
</div>
<div class="parity0 source"><a href="#l203" id="l203">   203</a> 
</div>
<div class="parity1 source"><a href="#l204" id="l204">   204</a> /** \brief Implements writing urdf::Model objects to a COLLADA DOM.
</div>
<div class="parity0 source"><a href="#l205" id="l205">   205</a> */
</div>
<div class="parity1 source"><a href="#l206" id="l206">   206</a> class ColladaWriter : public daeErrorHandler
</div>
<div class="parity0 source"><a href="#l207" id="l207">   207</a> {
</div>
<div class="parity1 source"><a href="#l208" id="l208">   208</a> private:
</div>
<div class="parity0 source"><a href="#l209" id="l209">   209</a>     struct SCENE
</div>
<div class="parity1 source"><a href="#l210" id="l210">   210</a>     {
</div>
<div class="parity0 source"><a href="#l211" id="l211">   211</a>         domVisual_sceneRef vscene;
</div>
<div class="parity1 source"><a href="#l212" id="l212">   212</a>         domKinematics_sceneRef kscene;
</div>
<div class="parity0 source"><a href="#l213" id="l213">   213</a>         domPhysics_sceneRef pscene;
</div>
<div class="parity1 source"><a href="#l214" id="l214">   214</a>         domInstance_with_extraRef viscene;
</div>
<div class="parity0 source"><a href="#l215" id="l215">   215</a>         domInstance_kinematics_sceneRef kiscene;
</div>
<div class="parity1 source"><a href="#l216" id="l216">   216</a>         domInstance_with_extraRef piscene;
</div>
<div class="parity0 source"><a href="#l217" id="l217">   217</a>     };
</div>
<div class="parity1 source"><a href="#l218" id="l218">   218</a> 
</div>
<div class="parity0 source"><a href="#l219" id="l219">   219</a>     struct LINKOUTPUT
</div>
<div class="parity1 source"><a href="#l220" id="l220">   220</a>     {
</div>
<div class="parity0 source"><a href="#l221" id="l221">   221</a>         list&lt;pair&lt;int,string&gt; &gt; listusedlinks;
</div>
<div class="parity1 source"><a href="#l222" id="l222">   222</a>         list&lt;pair&lt;int,string&gt; &gt; listprocesseddofs;
</div>
<div class="parity0 source"><a href="#l223" id="l223">   223</a>         daeElementRef plink;
</div>
<div class="parity1 source"><a href="#l224" id="l224">   224</a>         domNodeRef pnode;
</div>
<div class="parity0 source"><a href="#l225" id="l225">   225</a>     };
</div>
<div class="parity1 source"><a href="#l226" id="l226">   226</a> 
</div>
<div class="parity0 source"><a href="#l227" id="l227">   227</a>     struct kinematics_model_output
</div>
<div class="parity1 source"><a href="#l228" id="l228">   228</a>     {
</div>
<div class="parity0 source"><a href="#l229" id="l229">   229</a>         struct axis_output
</div>
<div class="parity1 source"><a href="#l230" id="l230">   230</a>         {
</div>
<div class="parity0 source"><a href="#l231" id="l231">   231</a>             //axis_output(const string&amp; sid, KinBody::JointConstPtr pjoint, int iaxis) : sid(sid), pjoint(pjoint), iaxis(iaxis) {}
</div>
<div class="parity1 source"><a href="#l232" id="l232">   232</a>         axis_output() : iaxis(0) {}
</div>
<div class="parity0 source"><a href="#l233" id="l233">   233</a>             string sid, nodesid;
</div>
<div class="parity1 source"><a href="#l234" id="l234">   234</a>             boost::shared_ptr&lt;const urdf::Joint&gt; pjoint;
</div>
<div class="parity0 source"><a href="#l235" id="l235">   235</a>             int iaxis;
</div>
<div class="parity1 source"><a href="#l236" id="l236">   236</a>             string jointnodesid;
</div>
<div class="parity0 source"><a href="#l237" id="l237">   237</a>         };
</div>
<div class="parity1 source"><a href="#l238" id="l238">   238</a>         domKinematics_modelRef kmodel;
</div>
<div class="parity0 source"><a href="#l239" id="l239">   239</a>         std::vector&lt;axis_output&gt; vaxissids;
</div>
<div class="parity1 source"><a href="#l240" id="l240">   240</a>         std::vector&lt;std::string &gt; vlinksids;
</div>
<div class="parity0 source"><a href="#l241" id="l241">   241</a>     };
</div>
<div class="parity1 source"><a href="#l242" id="l242">   242</a> 
</div>
<div class="parity0 source"><a href="#l243" id="l243">   243</a>     struct axis_sids
</div>
<div class="parity1 source"><a href="#l244" id="l244">   244</a>     {
</div>
<div class="parity0 source"><a href="#l245" id="l245">   245</a>     axis_sids(const string&amp; axissid, const string&amp; valuesid, const string&amp; jointnodesid) : axissid(axissid), valuesid(valuesid), jointnodesid(jointnodesid) {}
</div>
<div class="parity1 source"><a href="#l246" id="l246">   246</a>         string axissid, valuesid, jointnodesid;
</div>
<div class="parity0 source"><a href="#l247" id="l247">   247</a>     };
</div>
<div class="parity1 source"><a href="#l248" id="l248">   248</a> 
</div>
<div class="parity0 source"><a href="#l249" id="l249">   249</a>     struct instance_kinematics_model_output
</div>
<div class="parity1 source"><a href="#l250" id="l250">   250</a>     {
</div>
<div class="parity0 source"><a href="#l251" id="l251">   251</a>         domInstance_kinematics_modelRef ikm;
</div>
<div class="parity1 source"><a href="#l252" id="l252">   252</a>         std::vector&lt;axis_sids&gt; vaxissids;
</div>
<div class="parity0 source"><a href="#l253" id="l253">   253</a>         boost::shared_ptr&lt;kinematics_model_output&gt; kmout;
</div>
<div class="parity1 source"><a href="#l254" id="l254">   254</a>         std::vector&lt;std::pair&lt;std::string,std::string&gt; &gt; vkinematicsbindings;
</div>
<div class="parity0 source"><a href="#l255" id="l255">   255</a>     };
</div>
<div class="parity1 source"><a href="#l256" id="l256">   256</a> 
</div>
<div class="parity0 source"><a href="#l257" id="l257">   257</a>     struct instance_articulated_system_output
</div>
<div class="parity1 source"><a href="#l258" id="l258">   258</a>     {
</div>
<div class="parity0 source"><a href="#l259" id="l259">   259</a>         domInstance_articulated_systemRef ias;
</div>
<div class="parity1 source"><a href="#l260" id="l260">   260</a>         std::vector&lt;axis_sids&gt; vaxissids;
</div>
<div class="parity0 source"><a href="#l261" id="l261">   261</a>         std::vector&lt;std::string &gt; vlinksids;
</div>
<div class="parity1 source"><a href="#l262" id="l262">   262</a>         std::vector&lt;std::pair&lt;std::string,std::string&gt; &gt; vkinematicsbindings;
</div>
<div class="parity0 source"><a href="#l263" id="l263">   263</a>     };
</div>
<div class="parity1 source"><a href="#l264" id="l264">   264</a> 
</div>
<div class="parity0 source"><a href="#l265" id="l265">   265</a> public:
</div>
<div class="parity1 source"><a href="#l266" id="l266">   266</a>     ColladaWriter(const urdf::Model&amp; robot, int writeoptions) : _writeoptions(writeoptions), _robot(robot), _dom(NULL) {
</div>
<div class="parity0 source"><a href="#l267" id="l267">   267</a>         daeErrorHandler::setErrorHandler(this);        
</div>
<div class="parity1 source"><a href="#l268" id="l268">   268</a>         _collada.reset(new DAE);
</div>
<div class="parity0 source"><a href="#l269" id="l269">   269</a>         _collada-&gt;setIOPlugin(NULL);
</div>
<div class="parity1 source"><a href="#l270" id="l270">   270</a>         _collada-&gt;setDatabase(NULL);
</div>
<div class="parity0 source"><a href="#l271" id="l271">   271</a>         _importer.SetIOHandler(new ResourceIOSystem());
</div>
<div class="parity1 source"><a href="#l272" id="l272">   272</a>     }
</div>
<div class="parity0 source"><a href="#l273" id="l273">   273</a>     virtual ~ColladaWriter() {}
</div>
<div class="parity1 source"><a href="#l274" id="l274">   274</a> 
</div>
<div class="parity0 source"><a href="#l275" id="l275">   275</a>     boost::shared_ptr&lt;DAE&gt; convert()
</div>
<div class="parity1 source"><a href="#l276" id="l276">   276</a>     {
</div>
<div class="parity0 source"><a href="#l277" id="l277">   277</a>         try {
</div>
<div class="parity1 source"><a href="#l278" id="l278">   278</a>             const char* documentName = &quot;urdf_snapshot&quot;;
</div>
<div class="parity0 source"><a href="#l279" id="l279">   279</a>             daeDocument *doc = NULL;
</div>
<div class="parity1 source"><a href="#l280" id="l280">   280</a>             daeInt error = _collada-&gt;getDatabase()-&gt;insertDocument(documentName, &amp;doc ); // also creates a collada root
</div>
<div class="parity0 source"><a href="#l281" id="l281">   281</a>             if (error != DAE_OK || doc == NULL) {
</div>
<div class="parity1 source"><a href="#l282" id="l282">   282</a>                 throw ColladaUrdfException(&quot;Failed to create document&quot;);
</div>
<div class="parity0 source"><a href="#l283" id="l283">   283</a>             }
</div>
<div class="parity1 source"><a href="#l284" id="l284">   284</a>             _dom = daeSafeCast&lt;domCOLLADA&gt;(doc-&gt;getDomRoot());
</div>
<div class="parity0 source"><a href="#l285" id="l285">   285</a>             _dom-&gt;setAttribute(&quot;xmlns:math&quot;,&quot;http://www.w3.org/1998/Math/MathML&quot;);
</div>
<div class="parity1 source"><a href="#l286" id="l286">   286</a> 
</div>
<div class="parity0 source"><a href="#l287" id="l287">   287</a>             //create the required asset tag
</div>
<div class="parity1 source"><a href="#l288" id="l288">   288</a>             domAssetRef asset = daeSafeCast&lt;domAsset&gt;( _dom-&gt;add( COLLADA_ELEMENT_ASSET ) );
</div>
<div class="parity0 source"><a href="#l289" id="l289">   289</a>             {
</div>
<div class="parity1 source"><a href="#l290" id="l290">   290</a>                 // facet becomes owned by locale, so no need to explicitly delete
</div>
<div class="parity0 source"><a href="#l291" id="l291">   291</a>                 boost::posix_time::time_facet* facet = new boost::posix_time::time_facet(&quot;%Y-%m-%dT%H:%M:%s&quot;);
</div>
<div class="parity1 source"><a href="#l292" id="l292">   292</a>                 std::stringstream ss;
</div>
<div class="parity0 source"><a href="#l293" id="l293">   293</a>                 ss.imbue(std::locale(ss.getloc(), facet));
</div>
<div class="parity1 source"><a href="#l294" id="l294">   294</a>                 ss &lt;&lt; boost::posix_time::second_clock::local_time();
</div>
<div class="parity0 source"><a href="#l295" id="l295">   295</a> 
</div>
<div class="parity1 source"><a href="#l296" id="l296">   296</a>                 domAsset::domCreatedRef created = daeSafeCast&lt;domAsset::domCreated&gt;( asset-&gt;add( COLLADA_ELEMENT_CREATED ) );
</div>
<div class="parity0 source"><a href="#l297" id="l297">   297</a>                 created-&gt;setValue(ss.str().c_str());
</div>
<div class="parity1 source"><a href="#l298" id="l298">   298</a>                 domAsset::domModifiedRef modified = daeSafeCast&lt;domAsset::domModified&gt;( asset-&gt;add( COLLADA_ELEMENT_MODIFIED ) );
</div>
<div class="parity0 source"><a href="#l299" id="l299">   299</a>                 modified-&gt;setValue(ss.str().c_str());
</div>
<div class="parity1 source"><a href="#l300" id="l300">   300</a> 
</div>
<div class="parity0 source"><a href="#l301" id="l301">   301</a>                 domAsset::domContributorRef contrib = daeSafeCast&lt;domAsset::domContributor&gt;( asset-&gt;add( COLLADA_TYPE_CONTRIBUTOR ) );
</div>
<div class="parity1 source"><a href="#l302" id="l302">   302</a>                 domAsset::domContributor::domAuthoring_toolRef authoringtool = daeSafeCast&lt;domAsset::domContributor::domAuthoring_tool&gt;( contrib-&gt;add( COLLADA_ELEMENT_AUTHORING_TOOL ) );
</div>
<div class="parity0 source"><a href="#l303" id="l303">   303</a>                 authoringtool-&gt;setValue(&quot;URDF Collada Writer&quot;);
</div>
<div class="parity1 source"><a href="#l304" id="l304">   304</a> 
</div>
<div class="parity0 source"><a href="#l305" id="l305">   305</a>                 domAsset::domUnitRef units = daeSafeCast&lt;domAsset::domUnit&gt;( asset-&gt;add( COLLADA_ELEMENT_UNIT ) );
</div>
<div class="parity1 source"><a href="#l306" id="l306">   306</a>                 units-&gt;setMeter(1);
</div>
<div class="parity0 source"><a href="#l307" id="l307">   307</a>                 units-&gt;setName(&quot;meter&quot;);
</div>
<div class="parity1 source"><a href="#l308" id="l308">   308</a> 
</div>
<div class="parity0 source"><a href="#l309" id="l309">   309</a>                 domAsset::domUp_axisRef zup = daeSafeCast&lt;domAsset::domUp_axis&gt;( asset-&gt;add( COLLADA_ELEMENT_UP_AXIS ) );
</div>
<div class="parity1 source"><a href="#l310" id="l310">   310</a>                 zup-&gt;setValue(UP_AXIS_Z_UP);
</div>
<div class="parity0 source"><a href="#l311" id="l311">   311</a>             }
</div>
<div class="parity1 source"><a href="#l312" id="l312">   312</a> 
</div>
<div class="parity0 source"><a href="#l313" id="l313">   313</a>             _globalscene = _dom-&gt;getScene();
</div>
<div class="parity1 source"><a href="#l314" id="l314">   314</a>             if( !_globalscene ) {
</div>
<div class="parity0 source"><a href="#l315" id="l315">   315</a>                 _globalscene = daeSafeCast&lt;domCOLLADA::domScene&gt;( _dom-&gt;add( COLLADA_ELEMENT_SCENE ) );
</div>
<div class="parity1 source"><a href="#l316" id="l316">   316</a>             }
</div>
<div class="parity0 source"><a href="#l317" id="l317">   317</a> 
</div>
<div class="parity1 source"><a href="#l318" id="l318">   318</a>             _visualScenesLib = daeSafeCast&lt;domLibrary_visual_scenes&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_VISUAL_SCENES));
</div>
<div class="parity0 source"><a href="#l319" id="l319">   319</a>             _visualScenesLib-&gt;setId(&quot;vscenes&quot;);
</div>
<div class="parity1 source"><a href="#l320" id="l320">   320</a>             _geometriesLib = daeSafeCast&lt;domLibrary_geometries&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_GEOMETRIES));
</div>
<div class="parity0 source"><a href="#l321" id="l321">   321</a>             _geometriesLib-&gt;setId(&quot;geometries&quot;);
</div>
<div class="parity1 source"><a href="#l322" id="l322">   322</a>             _effectsLib = daeSafeCast&lt;domLibrary_effects&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_EFFECTS));
</div>
<div class="parity0 source"><a href="#l323" id="l323">   323</a>             _effectsLib-&gt;setId(&quot;effects&quot;);
</div>
<div class="parity1 source"><a href="#l324" id="l324">   324</a>             _materialsLib = daeSafeCast&lt;domLibrary_materials&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_MATERIALS));
</div>
<div class="parity0 source"><a href="#l325" id="l325">   325</a>             _materialsLib-&gt;setId(&quot;materials&quot;);
</div>
<div class="parity1 source"><a href="#l326" id="l326">   326</a>             _kinematicsModelsLib = daeSafeCast&lt;domLibrary_kinematics_models&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_KINEMATICS_MODELS));
</div>
<div class="parity0 source"><a href="#l327" id="l327">   327</a>             _kinematicsModelsLib-&gt;setId(&quot;kmodels&quot;);
</div>
<div class="parity1 source"><a href="#l328" id="l328">   328</a>             _articulatedSystemsLib = daeSafeCast&lt;domLibrary_articulated_systems&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_ARTICULATED_SYSTEMS));
</div>
<div class="parity0 source"><a href="#l329" id="l329">   329</a>             _articulatedSystemsLib-&gt;setId(&quot;asystems&quot;);
</div>
<div class="parity1 source"><a href="#l330" id="l330">   330</a>             _kinematicsScenesLib = daeSafeCast&lt;domLibrary_kinematics_scenes&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_KINEMATICS_SCENES));
</div>
<div class="parity0 source"><a href="#l331" id="l331">   331</a>             _kinematicsScenesLib-&gt;setId(&quot;kscenes&quot;);
</div>
<div class="parity1 source"><a href="#l332" id="l332">   332</a>             _physicsScenesLib = daeSafeCast&lt;domLibrary_physics_scenes&gt;(_dom-&gt;add(COLLADA_ELEMENT_LIBRARY_PHYSICS_SCENES));
</div>
<div class="parity0 source"><a href="#l333" id="l333">   333</a>             _physicsScenesLib-&gt;setId(&quot;pscenes&quot;);
</div>
<div class="parity1 source"><a href="#l334" id="l334">   334</a>             domExtraRef pextra_library_sensors = daeSafeCast&lt;domExtra&gt;(_dom-&gt;add(COLLADA_ELEMENT_EXTRA));
</div>
<div class="parity0 source"><a href="#l335" id="l335">   335</a>             pextra_library_sensors-&gt;setId(&quot;sensors&quot;);
</div>
<div class="parity1 source"><a href="#l336" id="l336">   336</a>             pextra_library_sensors-&gt;setType(&quot;library_sensors&quot;);
</div>
<div class="parity0 source"><a href="#l337" id="l337">   337</a>             _sensorsLib = daeSafeCast&lt;domTechnique&gt;(pextra_library_sensors-&gt;add(COLLADA_ELEMENT_TECHNIQUE));
</div>
<div class="parity1 source"><a href="#l338" id="l338">   338</a>             _sensorsLib-&gt;setProfile(&quot;OpenRAVE&quot;); ///&lt; documented profile on robot extensions
</div>
<div class="parity0 source"><a href="#l339" id="l339">   339</a> 
</div>
<div class="parity1 source"><a href="#l340" id="l340">   340</a>             _CreateScene();
</div>
<div class="parity0 source"><a href="#l341" id="l341">   341</a>             _WritePhysics();
</div>
<div class="parity1 source"><a href="#l342" id="l342">   342</a>             _WriteRobot();
</div>
<div class="parity0 source"><a href="#l343" id="l343">   343</a>             _WriteBindingsInstance_kinematics_scene();
</div>
<div class="parity1 source"><a href="#l344" id="l344">   344</a>             return _collada;
</div>
<div class="parity0 source"><a href="#l345" id="l345">   345</a>         }
</div>
<div class="parity1 source"><a href="#l346" id="l346">   346</a>         catch (ColladaUrdfException ex) {
</div>
<div class="parity0 source"><a href="#l347" id="l347">   347</a>             ROS_ERROR(&quot;Error converting: %s&quot;, ex.what());
</div>
<div class="parity1 source"><a href="#l348" id="l348">   348</a>             return boost::shared_ptr&lt;DAE&gt;();
</div>
<div class="parity0 source"><a href="#l349" id="l349">   349</a>         }
</div>
<div class="parity1 source"><a href="#l350" id="l350">   350</a>     }
</div>
<div class="parity0 source"><a href="#l351" id="l351">   351</a> 
</div>
<div class="parity1 source"><a href="#l352" id="l352">   352</a> protected:
</div>
<div class="parity0 source"><a href="#l353" id="l353">   353</a>     virtual void handleError(daeString msg) { throw ColladaUrdfException(msg); }
</div>
<div class="parity1 source"><a href="#l354" id="l354">   354</a>     virtual void handleWarning(daeString msg) { std::cerr &lt;&lt; &quot;COLLADA DOM warning: &quot; &lt;&lt; msg &lt;&lt; std::endl; }
</div>
<div class="parity0 source"><a href="#l355" id="l355">   355</a> 
</div>
<div class="parity1 source"><a href="#l356" id="l356">   356</a>     void _CreateScene()
</div>
<div class="parity0 source"><a href="#l357" id="l357">   357</a>     {
</div>
<div class="parity1 source"><a href="#l358" id="l358">   358</a>         // Create visual scene
</div>
<div class="parity0 source"><a href="#l359" id="l359">   359</a>         _scene.vscene = daeSafeCast&lt;domVisual_scene&gt;(_visualScenesLib-&gt;add(COLLADA_ELEMENT_VISUAL_SCENE));
</div>
<div class="parity1 source"><a href="#l360" id="l360">   360</a>         _scene.vscene-&gt;setId(&quot;vscene&quot;);
</div>
<div class="parity0 source"><a href="#l361" id="l361">   361</a>         _scene.vscene-&gt;setName(&quot;URDF Visual Scene&quot;);
</div>
<div class="parity1 source"><a href="#l362" id="l362">   362</a> 
</div>
<div class="parity0 source"><a href="#l363" id="l363">   363</a>         // Create kinematics scene
</div>
<div class="parity1 source"><a href="#l364" id="l364">   364</a>         _scene.kscene = daeSafeCast&lt;domKinematics_scene&gt;(_kinematicsScenesLib-&gt;add(COLLADA_ELEMENT_KINEMATICS_SCENE));
</div>
<div class="parity0 source"><a href="#l365" id="l365">   365</a>         _scene.kscene-&gt;setId(&quot;kscene&quot;);
</div>
<div class="parity1 source"><a href="#l366" id="l366">   366</a>         _scene.kscene-&gt;setName(&quot;URDF Kinematics Scene&quot;);
</div>
<div class="parity0 source"><a href="#l367" id="l367">   367</a> 
</div>
<div class="parity1 source"><a href="#l368" id="l368">   368</a>         // Create physic scene
</div>
<div class="parity0 source"><a href="#l369" id="l369">   369</a>         _scene.pscene = daeSafeCast&lt;domPhysics_scene&gt;(_physicsScenesLib-&gt;add(COLLADA_ELEMENT_PHYSICS_SCENE));
</div>
<div class="parity1 source"><a href="#l370" id="l370">   370</a>         _scene.pscene-&gt;setId(&quot;pscene&quot;);
</div>
<div class="parity0 source"><a href="#l371" id="l371">   371</a>         _scene.pscene-&gt;setName(&quot;URDF Physics Scene&quot;);
</div>
<div class="parity1 source"><a href="#l372" id="l372">   372</a> 
</div>
<div class="parity0 source"><a href="#l373" id="l373">   373</a>         // Create instance visual scene
</div>
<div class="parity1 source"><a href="#l374" id="l374">   374</a>         _scene.viscene = daeSafeCast&lt;domInstance_with_extra&gt;(_globalscene-&gt;add( COLLADA_ELEMENT_INSTANCE_VISUAL_SCENE ));
</div>
<div class="parity0 source"><a href="#l375" id="l375">   375</a>         _scene.viscene-&gt;setUrl( (string(&quot;#&quot;) + string(_scene.vscene-&gt;getID())).c_str() );
</div>
<div class="parity1 source"><a href="#l376" id="l376">   376</a> 
</div>
<div class="parity0 source"><a href="#l377" id="l377">   377</a>         // Create instance kinematics scene
</div>
<div class="parity1 source"><a href="#l378" id="l378">   378</a>         _scene.kiscene = daeSafeCast&lt;domInstance_kinematics_scene&gt;(_globalscene-&gt;add( COLLADA_ELEMENT_INSTANCE_KINEMATICS_SCENE ));
</div>
<div class="parity0 source"><a href="#l379" id="l379">   379</a>         _scene.kiscene-&gt;setUrl( (string(&quot;#&quot;) + string(_scene.kscene-&gt;getID())).c_str() );
</div>
<div class="parity1 source"><a href="#l380" id="l380">   380</a> 
</div>
<div class="parity0 source"><a href="#l381" id="l381">   381</a>         // Create instance physics scene
</div>
<div class="parity1 source"><a href="#l382" id="l382">   382</a>         _scene.piscene = daeSafeCast&lt;domInstance_with_extra&gt;(_globalscene-&gt;add( COLLADA_ELEMENT_INSTANCE_PHYSICS_SCENE ));
</div>
<div class="parity0 source"><a href="#l383" id="l383">   383</a>         _scene.piscene-&gt;setUrl( (string(&quot;#&quot;) + string(_scene.pscene-&gt;getID())).c_str() );
</div>
<div class="parity1 source"><a href="#l384" id="l384">   384</a>     }
</div>
<div class="parity0 source"><a href="#l385" id="l385">   385</a> 
</div>
<div class="parity1 source"><a href="#l386" id="l386">   386</a>     void _WritePhysics() {
</div>
<div class="parity0 source"><a href="#l387" id="l387">   387</a>         domPhysics_scene::domTechnique_commonRef common = daeSafeCast&lt;domPhysics_scene::domTechnique_common&gt;(_scene.pscene-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity1 source"><a href="#l388" id="l388">   388</a>         //  Create gravity
</div>
<div class="parity0 source"><a href="#l389" id="l389">   389</a>         domTargetable_float3Ref g = daeSafeCast&lt;domTargetable_float3&gt;(common-&gt;add(COLLADA_ELEMENT_GRAVITY));
</div>
<div class="parity1 source"><a href="#l390" id="l390">   390</a>         g-&gt;getValue().set3 (0,0,0);
</div>
<div class="parity0 source"><a href="#l391" id="l391">   391</a>     }
</div>
<div class="parity1 source"><a href="#l392" id="l392">   392</a> 
</div>
<div class="parity0 source"><a href="#l393" id="l393">   393</a>     /// \brief Write kinematic body in a given scene
</div>
<div class="parity1 source"><a href="#l394" id="l394">   394</a>     void _WriteRobot(int id = 0)
</div>
<div class="parity0 source"><a href="#l395" id="l395">   395</a>     {
</div>
<div class="parity1 source"><a href="#l396" id="l396">   396</a>         ROS_DEBUG_STREAM(str(boost::format(&quot;writing robot as instance_articulated_system (%d) %s\n&quot;)%id%_robot.getName()));
</div>
<div class="parity0 source"><a href="#l397" id="l397">   397</a>         string asid = _ComputeId(str(boost::format(&quot;robot%d&quot;)%id));
</div>
<div class="parity1 source"><a href="#l398" id="l398">   398</a>         string askid = _ComputeId(str(boost::format(&quot;%s_kinematics&quot;)%asid));
</div>
<div class="parity0 source"><a href="#l399" id="l399">   399</a>         string asmid = _ComputeId(str(boost::format(&quot;%s_motion&quot;)%asid));
</div>
<div class="parity1 source"><a href="#l400" id="l400">   400</a>         string iassid = _ComputeId(str(boost::format(&quot;%s_inst&quot;)%asmid));
</div>
<div class="parity0 source"><a href="#l401" id="l401">   401</a> 
</div>
<div class="parity1 source"><a href="#l402" id="l402">   402</a>         domInstance_articulated_systemRef ias = daeSafeCast&lt;domInstance_articulated_system&gt;(_scene.kscene-&gt;add(COLLADA_ELEMENT_INSTANCE_ARTICULATED_SYSTEM));
</div>
<div class="parity0 source"><a href="#l403" id="l403">   403</a>         ias-&gt;setSid(iassid.c_str());
</div>
<div class="parity1 source"><a href="#l404" id="l404">   404</a>         ias-&gt;setUrl((string(&quot;#&quot;)+asmid).c_str());
</div>
<div class="parity0 source"><a href="#l405" id="l405">   405</a>         ias-&gt;setName(_robot.getName().c_str());
</div>
<div class="parity1 source"><a href="#l406" id="l406">   406</a> 
</div>
<div class="parity0 source"><a href="#l407" id="l407">   407</a>         _iasout.reset(new instance_articulated_system_output());
</div>
<div class="parity1 source"><a href="#l408" id="l408">   408</a>         _iasout-&gt;ias = ias;
</div>
<div class="parity0 source"><a href="#l409" id="l409">   409</a> 
</div>
<div class="parity1 source"><a href="#l410" id="l410">   410</a>         // motion info
</div>
<div class="parity0 source"><a href="#l411" id="l411">   411</a>         domArticulated_systemRef articulated_system_motion = daeSafeCast&lt;domArticulated_system&gt;(_articulatedSystemsLib-&gt;add(COLLADA_ELEMENT_ARTICULATED_SYSTEM));
</div>
<div class="parity1 source"><a href="#l412" id="l412">   412</a>         articulated_system_motion-&gt;setId(asmid.c_str());
</div>
<div class="parity0 source"><a href="#l413" id="l413">   413</a>         domMotionRef motion = daeSafeCast&lt;domMotion&gt;(articulated_system_motion-&gt;add(COLLADA_ELEMENT_MOTION));
</div>
<div class="parity1 source"><a href="#l414" id="l414">   414</a>         domMotion_techniqueRef mt = daeSafeCast&lt;domMotion_technique&gt;(motion-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity0 source"><a href="#l415" id="l415">   415</a>         domInstance_articulated_systemRef ias_motion = daeSafeCast&lt;domInstance_articulated_system&gt;(motion-&gt;add(COLLADA_ELEMENT_INSTANCE_ARTICULATED_SYSTEM));
</div>
<div class="parity1 source"><a href="#l416" id="l416">   416</a>         ias_motion-&gt;setUrl(str(boost::format(&quot;#%s&quot;)%askid).c_str());
</div>
<div class="parity0 source"><a href="#l417" id="l417">   417</a> 
</div>
<div class="parity1 source"><a href="#l418" id="l418">   418</a>         // kinematics info
</div>
<div class="parity0 source"><a href="#l419" id="l419">   419</a>         domArticulated_systemRef articulated_system_kinematics = daeSafeCast&lt;domArticulated_system&gt;(_articulatedSystemsLib-&gt;add(COLLADA_ELEMENT_ARTICULATED_SYSTEM));
</div>
<div class="parity1 source"><a href="#l420" id="l420">   420</a>         articulated_system_kinematics-&gt;setId(askid.c_str());
</div>
<div class="parity0 source"><a href="#l421" id="l421">   421</a>         domKinematicsRef kinematics = daeSafeCast&lt;domKinematics&gt;(articulated_system_kinematics-&gt;add(COLLADA_ELEMENT_KINEMATICS));
</div>
<div class="parity1 source"><a href="#l422" id="l422">   422</a>         domKinematics_techniqueRef kt = daeSafeCast&lt;domKinematics_technique&gt;(kinematics-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity0 source"><a href="#l423" id="l423">   423</a> 
</div>
<div class="parity1 source"><a href="#l424" id="l424">   424</a>         _WriteInstance_kinematics_model(kinematics,askid,id);
</div>
<div class="parity0 source"><a href="#l425" id="l425">   425</a> 
</div>
<div class="parity1 source"><a href="#l426" id="l426">   426</a>         for(size_t idof = 0; idof &lt; _ikmout-&gt;vaxissids.size(); ++idof) {
</div>
<div class="parity0 source"><a href="#l427" id="l427">   427</a>             string axis_infosid = _ComputeId(str(boost::format(&quot;axis_info_inst%d&quot;)%idof));
</div>
<div class="parity1 source"><a href="#l428" id="l428">   428</a>             boost::shared_ptr&lt;const urdf::Joint&gt; pjoint = _ikmout-&gt;kmout-&gt;vaxissids.at(idof).pjoint;
</div>
<div class="parity0 source"><a href="#l429" id="l429">   429</a>             BOOST_ASSERT(_mapjointindices[pjoint] == (int)idof);
</div>
<div class="parity1 source"><a href="#l430" id="l430">   430</a>             //int iaxis = _ikmout-&gt;kmout-&gt;vaxissids.at(idof).iaxis;
</div>
<div class="parity0 source"><a href="#l431" id="l431">   431</a> 
</div>
<div class="parity1 source"><a href="#l432" id="l432">   432</a>             //  Kinematics axis info
</div>
<div class="parity0 source"><a href="#l433" id="l433">   433</a>             domKinematics_axis_infoRef kai = daeSafeCast&lt;domKinematics_axis_info&gt;(kt-&gt;add(COLLADA_ELEMENT_AXIS_INFO));
</div>
<div class="parity1 source"><a href="#l434" id="l434">   434</a>             kai-&gt;setAxis(str(boost::format(&quot;%s/%s&quot;)%_ikmout-&gt;kmout-&gt;kmodel-&gt;getID()%_ikmout-&gt;kmout-&gt;vaxissids.at(idof).sid).c_str());
</div>
<div class="parity0 source"><a href="#l435" id="l435">   435</a>             kai-&gt;setSid(axis_infosid.c_str());
</div>
<div class="parity1 source"><a href="#l436" id="l436">   436</a>             bool bactive = !pjoint-&gt;mimic;
</div>
<div class="parity0 source"><a href="#l437" id="l437">   437</a>             double flower=0, fupper=0;
</div>
<div class="parity1 source"><a href="#l438" id="l438">   438</a>             if( pjoint-&gt;type != urdf::Joint::CONTINUOUS ) {
</div>
<div class="parity0 source"><a href="#l439" id="l439">   439</a>                 if( !!pjoint-&gt;limits ) {
</div>
<div class="parity1 source"><a href="#l440" id="l440">   440</a>                     flower = pjoint-&gt;limits-&gt;lower;
</div>
<div class="parity0 source"><a href="#l441" id="l441">   441</a>                     fupper = pjoint-&gt;limits-&gt;upper;
</div>
<div class="parity1 source"><a href="#l442" id="l442">   442</a>                 }
</div>
<div class="parity0 source"><a href="#l443" id="l443">   443</a>                 if( flower == fupper ) {
</div>
<div class="parity1 source"><a href="#l444" id="l444">   444</a>                     bactive = false;
</div>
<div class="parity0 source"><a href="#l445" id="l445">   445</a>                 }
</div>
<div class="parity1 source"><a href="#l446" id="l446">   446</a>                 double fmult = 1.0;
</div>
<div class="parity0 source"><a href="#l447" id="l447">   447</a>                 if( pjoint-&gt;type != urdf::Joint::PRISMATIC ) {
</div>
<div class="parity1 source"><a href="#l448" id="l448">   448</a>                     fmult = 180.0/M_PI;
</div>
<div class="parity0 source"><a href="#l449" id="l449">   449</a>                 }
</div>
<div class="parity1 source"><a href="#l450" id="l450">   450</a>                 domKinematics_limitsRef plimits = daeSafeCast&lt;domKinematics_limits&gt;(kai-&gt;add(COLLADA_ELEMENT_LIMITS));
</div>
<div class="parity0 source"><a href="#l451" id="l451">   451</a>                 daeSafeCast&lt;domCommon_float_or_param::domFloat&gt;(plimits-&gt;add(COLLADA_ELEMENT_MIN)-&gt;add(COLLADA_ELEMENT_FLOAT))-&gt;setValue(flower*fmult);
</div>
<div class="parity1 source"><a href="#l452" id="l452">   452</a>                 daeSafeCast&lt;domCommon_float_or_param::domFloat&gt;(plimits-&gt;add(COLLADA_ELEMENT_MAX)-&gt;add(COLLADA_ELEMENT_FLOAT))-&gt;setValue(fupper*fmult);
</div>
<div class="parity0 source"><a href="#l453" id="l453">   453</a>             }
</div>
<div class="parity1 source"><a href="#l454" id="l454">   454</a> 
</div>
<div class="parity0 source"><a href="#l455" id="l455">   455</a>             domCommon_bool_or_paramRef active = daeSafeCast&lt;domCommon_bool_or_param&gt;(kai-&gt;add(COLLADA_ELEMENT_ACTIVE));
</div>
<div class="parity1 source"><a href="#l456" id="l456">   456</a>             daeSafeCast&lt;domCommon_bool_or_param::domBool&gt;(active-&gt;add(COLLADA_ELEMENT_BOOL))-&gt;setValue(bactive);
</div>
<div class="parity0 source"><a href="#l457" id="l457">   457</a>             domCommon_bool_or_paramRef locked = daeSafeCast&lt;domCommon_bool_or_param&gt;(kai-&gt;add(COLLADA_ELEMENT_LOCKED));
</div>
<div class="parity1 source"><a href="#l458" id="l458">   458</a>             daeSafeCast&lt;domCommon_bool_or_param::domBool&gt;(locked-&gt;add(COLLADA_ELEMENT_BOOL))-&gt;setValue(false);
</div>
<div class="parity0 source"><a href="#l459" id="l459">   459</a>         
</div>
<div class="parity1 source"><a href="#l460" id="l460">   460</a>             //  Motion axis info
</div>
<div class="parity0 source"><a href="#l461" id="l461">   461</a>             domMotion_axis_infoRef mai = daeSafeCast&lt;domMotion_axis_info&gt;(mt-&gt;add(COLLADA_ELEMENT_AXIS_INFO));
</div>
<div class="parity1 source"><a href="#l462" id="l462">   462</a>             mai-&gt;setAxis(str(boost::format(&quot;%s/%s&quot;)%askid%axis_infosid).c_str());
</div>
<div class="parity0 source"><a href="#l463" id="l463">   463</a>             if( !!pjoint-&gt;limits ) {
</div>
<div class="parity1 source"><a href="#l464" id="l464">   464</a>                 domCommon_float_or_paramRef speed = daeSafeCast&lt;domCommon_float_or_param&gt;(mai-&gt;add(COLLADA_ELEMENT_SPEED));
</div>
<div class="parity0 source"><a href="#l465" id="l465">   465</a>                 daeSafeCast&lt;domCommon_float_or_param::domFloat&gt;(speed-&gt;add(COLLADA_ELEMENT_FLOAT))-&gt;setValue(pjoint-&gt;limits-&gt;velocity);
</div>
<div class="parity1 source"><a href="#l466" id="l466">   466</a>                 domCommon_float_or_paramRef accel = daeSafeCast&lt;domCommon_float_or_param&gt;(mai-&gt;add(COLLADA_ELEMENT_ACCELERATION));
</div>
<div class="parity0 source"><a href="#l467" id="l467">   467</a>                 daeSafeCast&lt;domCommon_float_or_param::domFloat&gt;(accel-&gt;add(COLLADA_ELEMENT_FLOAT))-&gt;setValue(pjoint-&gt;limits-&gt;effort);
</div>
<div class="parity1 source"><a href="#l468" id="l468">   468</a>             }
</div>
<div class="parity0 source"><a href="#l469" id="l469">   469</a>         }
</div>
<div class="parity1 source"><a href="#l470" id="l470">   470</a> 
</div>
<div class="parity0 source"><a href="#l471" id="l471">   471</a>         // write the bindings
</div>
<div class="parity1 source"><a href="#l472" id="l472">   472</a>         string asmsym = _ComputeId(str(boost::format(&quot;%s_%s&quot;)%asmid%_ikmout-&gt;ikm-&gt;getSid()));
</div>
<div class="parity0 source"><a href="#l473" id="l473">   473</a>         string assym = _ComputeId(str(boost::format(&quot;%s_%s&quot;)%_scene.kscene-&gt;getID()%_ikmout-&gt;ikm-&gt;getSid()));
</div>
<div class="parity1 source"><a href="#l474" id="l474">   474</a>         FOREACH(it, _ikmout-&gt;vkinematicsbindings) {
</div>
<div class="parity0 source"><a href="#l475" id="l475">   475</a>             domKinematics_newparamRef abm = daeSafeCast&lt;domKinematics_newparam&gt;(ias_motion-&gt;add(COLLADA_ELEMENT_NEWPARAM));
</div>
<div class="parity1 source"><a href="#l476" id="l476">   476</a>             abm-&gt;setSid(asmsym.c_str());
</div>
<div class="parity0 source"><a href="#l477" id="l477">   477</a>             daeSafeCast&lt;domKinematics_newparam::domSIDREF&gt;(abm-&gt;add(COLLADA_ELEMENT_SIDREF))-&gt;setValue(str(boost::format(&quot;%s/%s&quot;)%askid%it-&gt;first).c_str());
</div>
<div class="parity1 source"><a href="#l478" id="l478">   478</a>             domKinematics_bindRef ab = daeSafeCast&lt;domKinematics_bind&gt;(ias-&gt;add(COLLADA_ELEMENT_BIND));
</div>
<div class="parity0 source"><a href="#l479" id="l479">   479</a>             ab-&gt;setSymbol(assym.c_str());
</div>
<div class="parity1 source"><a href="#l480" id="l480">   480</a>             daeSafeCast&lt;domKinematics_param&gt;(ab-&gt;add(COLLADA_ELEMENT_PARAM))-&gt;setRef(str(boost::format(&quot;%s/%s&quot;)%asmid%asmsym).c_str());
</div>
<div class="parity0 source"><a href="#l481" id="l481">   481</a>             _iasout-&gt;vkinematicsbindings.push_back(make_pair(string(ab-&gt;getSymbol()), it-&gt;second));
</div>
<div class="parity1 source"><a href="#l482" id="l482">   482</a>         }
</div>
<div class="parity0 source"><a href="#l483" id="l483">   483</a>         for(size_t idof = 0; idof &lt; _ikmout-&gt;vaxissids.size(); ++idof) {
</div>
<div class="parity1 source"><a href="#l484" id="l484">   484</a>             const axis_sids&amp; kas = _ikmout-&gt;vaxissids.at(idof);
</div>
<div class="parity0 source"><a href="#l485" id="l485">   485</a>             domKinematics_newparamRef abm = daeSafeCast&lt;domKinematics_newparam&gt;(ias_motion-&gt;add(COLLADA_ELEMENT_NEWPARAM));
</div>
<div class="parity1 source"><a href="#l486" id="l486">   486</a>             abm-&gt;setSid(_ComputeId(str(boost::format(&quot;%s_%s&quot;)%asmid%kas.axissid)).c_str());
</div>
<div class="parity0 source"><a href="#l487" id="l487">   487</a>             daeSafeCast&lt;domKinematics_newparam::domSIDREF&gt;(abm-&gt;add(COLLADA_ELEMENT_SIDREF))-&gt;setValue(str(boost::format(&quot;%s/%s&quot;)%askid%kas.axissid).c_str());
</div>
<div class="parity1 source"><a href="#l488" id="l488">   488</a>             domKinematics_bindRef ab = daeSafeCast&lt;domKinematics_bind&gt;(ias-&gt;add(COLLADA_ELEMENT_BIND));
</div>
<div class="parity0 source"><a href="#l489" id="l489">   489</a>             ab-&gt;setSymbol(str(boost::format(&quot;%s_%s&quot;)%assym%kas.axissid).c_str());
</div>
<div class="parity1 source"><a href="#l490" id="l490">   490</a>             daeSafeCast&lt;domKinematics_param&gt;(ab-&gt;add(COLLADA_ELEMENT_PARAM))-&gt;setRef(str(boost::format(&quot;%s/%s_%s&quot;)%asmid%asmid%kas.axissid).c_str());
</div>
<div class="parity0 source"><a href="#l491" id="l491">   491</a>             string valuesid;
</div>
<div class="parity1 source"><a href="#l492" id="l492">   492</a>             if( kas.valuesid.size() &gt; 0 ) {
</div>
<div class="parity0 source"><a href="#l493" id="l493">   493</a>                 domKinematics_newparamRef abmvalue = daeSafeCast&lt;domKinematics_newparam&gt;(ias_motion-&gt;add(COLLADA_ELEMENT_NEWPARAM));
</div>
<div class="parity1 source"><a href="#l494" id="l494">   494</a>                 abmvalue-&gt;setSid(_ComputeId(str(boost::format(&quot;%s_%s&quot;)%asmid%kas.valuesid)).c_str());
</div>
<div class="parity0 source"><a href="#l495" id="l495">   495</a>                 daeSafeCast&lt;domKinematics_newparam::domSIDREF&gt;(abmvalue-&gt;add(COLLADA_ELEMENT_SIDREF))-&gt;setValue(str(boost::format(&quot;%s/%s&quot;)%askid%kas.valuesid).c_str());
</div>
<div class="parity1 source"><a href="#l496" id="l496">   496</a>                 domKinematics_bindRef abvalue = daeSafeCast&lt;domKinematics_bind&gt;(ias-&gt;add(COLLADA_ELEMENT_BIND));
</div>
<div class="parity0 source"><a href="#l497" id="l497">   497</a>                 valuesid = _ComputeId(str(boost::format(&quot;%s_%s&quot;)%assym%kas.valuesid));
</div>
<div class="parity1 source"><a href="#l498" id="l498">   498</a>                 abvalue-&gt;setSymbol(valuesid.c_str());
</div>
<div class="parity0 source"><a href="#l499" id="l499">   499</a>                 daeSafeCast&lt;domKinematics_param&gt;(abvalue-&gt;add(COLLADA_ELEMENT_PARAM))-&gt;setRef(str(boost::format(&quot;%s/%s_%s&quot;)%asmid%asmid%kas.valuesid).c_str());
</div>
<div class="parity1 source"><a href="#l500" id="l500">   500</a>             }
</div>
<div class="parity0 source"><a href="#l501" id="l501">   501</a>             _iasout-&gt;vaxissids.push_back(axis_sids(ab-&gt;getSymbol(),valuesid,kas.jointnodesid));
</div>
<div class="parity1 source"><a href="#l502" id="l502">   502</a>         }
</div>
<div class="parity0 source"><a href="#l503" id="l503">   503</a>     }
</div>
<div class="parity1 source"><a href="#l504" id="l504">   504</a> 
</div>
<div class="parity0 source"><a href="#l505" id="l505">   505</a>     /// \brief Write kinematic body in a given scene
</div>
<div class="parity1 source"><a href="#l506" id="l506">   506</a>     virtual void _WriteInstance_kinematics_model(daeElementRef parent, const string&amp; sidscope, int id)
</div>
<div class="parity0 source"><a href="#l507" id="l507">   507</a>     {
</div>
<div class="parity1 source"><a href="#l508" id="l508">   508</a>         ROS_DEBUG_STREAM(str(boost::format(&quot;writing instance_kinematics_model %s\n&quot;)%_robot.getName()));
</div>
<div class="parity0 source"><a href="#l509" id="l509">   509</a>         boost::shared_ptr&lt;kinematics_model_output&gt; kmout = WriteKinematics_model(id);
</div>
<div class="parity1 source"><a href="#l510" id="l510">   510</a> 
</div>
<div class="parity0 source"><a href="#l511" id="l511">   511</a>         _ikmout.reset(new instance_kinematics_model_output());
</div>
<div class="parity1 source"><a href="#l512" id="l512">   512</a>         _ikmout-&gt;kmout = kmout;
</div>
<div class="parity0 source"><a href="#l513" id="l513">   513</a>         _ikmout-&gt;ikm = daeSafeCast&lt;domInstance_kinematics_model&gt;(parent-&gt;add(COLLADA_ELEMENT_INSTANCE_KINEMATICS_MODEL));
</div>
<div class="parity1 source"><a href="#l514" id="l514">   514</a> 
</div>
<div class="parity0 source"><a href="#l515" id="l515">   515</a>         string symscope, refscope;
</div>
<div class="parity1 source"><a href="#l516" id="l516">   516</a>         if( sidscope.size() &gt; 0 ) {
</div>
<div class="parity0 source"><a href="#l517" id="l517">   517</a>             symscope = sidscope+string(&quot;_&quot;);
</div>
<div class="parity1 source"><a href="#l518" id="l518">   518</a>             refscope = sidscope+string(&quot;/&quot;);
</div>
<div class="parity0 source"><a href="#l519" id="l519">   519</a>         }
</div>
<div class="parity1 source"><a href="#l520" id="l520">   520</a>         string ikmsid = _ComputeId(str(boost::format(&quot;%s_inst&quot;)%kmout-&gt;kmodel-&gt;getID()));
</div>
<div class="parity0 source"><a href="#l521" id="l521">   521</a>         _ikmout-&gt;ikm-&gt;setUrl(str(boost::format(&quot;#%s&quot;)%kmout-&gt;kmodel-&gt;getID()).c_str());
</div>
<div class="parity1 source"><a href="#l522" id="l522">   522</a>         _ikmout-&gt;ikm-&gt;setSid(ikmsid.c_str());
</div>
<div class="parity0 source"><a href="#l523" id="l523">   523</a> 
</div>
<div class="parity1 source"><a href="#l524" id="l524">   524</a>         domKinematics_newparamRef kbind = daeSafeCast&lt;domKinematics_newparam&gt;(_ikmout-&gt;ikm-&gt;add(COLLADA_ELEMENT_NEWPARAM));
</div>
<div class="parity0 source"><a href="#l525" id="l525">   525</a>         kbind-&gt;setSid(_ComputeId(symscope+ikmsid).c_str());
</div>
<div class="parity1 source"><a href="#l526" id="l526">   526</a>         daeSafeCast&lt;domKinematics_newparam::domSIDREF&gt;(kbind-&gt;add(COLLADA_ELEMENT_SIDREF))-&gt;setValue((refscope+ikmsid).c_str());
</div>
<div class="parity0 source"><a href="#l527" id="l527">   527</a>         _ikmout-&gt;vkinematicsbindings.push_back(make_pair(string(kbind-&gt;getSid()), str(boost::format(&quot;visual%d/node0&quot;)%id)));
</div>
<div class="parity1 source"><a href="#l528" id="l528">   528</a> 
</div>
<div class="parity0 source"><a href="#l529" id="l529">   529</a>         _ikmout-&gt;vaxissids.reserve(kmout-&gt;vaxissids.size());
</div>
<div class="parity1 source"><a href="#l530" id="l530">   530</a>         int i = 0;
</div>
<div class="parity0 source"><a href="#l531" id="l531">   531</a>         FOREACH(it,kmout-&gt;vaxissids) {
</div>
<div class="parity1 source"><a href="#l532" id="l532">   532</a>             domKinematics_newparamRef kbind = daeSafeCast&lt;domKinematics_newparam&gt;(_ikmout-&gt;ikm-&gt;add(COLLADA_ELEMENT_NEWPARAM));
</div>
<div class="parity0 source"><a href="#l533" id="l533">   533</a>             string ref = it-&gt;sid;
</div>
<div class="parity1 source"><a href="#l534" id="l534">   534</a>             size_t index = ref.find(&quot;/&quot;);
</div>
<div class="parity0 source"><a href="#l535" id="l535">   535</a>             while(index != string::npos) {
</div>
<div class="parity1 source"><a href="#l536" id="l536">   536</a>                 ref[index] = '.';
</div>
<div class="parity0 source"><a href="#l537" id="l537">   537</a>                 index = ref.find(&quot;/&quot;,index+1);
</div>
<div class="parity1 source"><a href="#l538" id="l538">   538</a>             }
</div>
<div class="parity0 source"><a href="#l539" id="l539">   539</a>             string sid = _ComputeId(symscope+ikmsid+&quot;_&quot;+ref);
</div>
<div class="parity1 source"><a href="#l540" id="l540">   540</a>             kbind-&gt;setSid(sid.c_str());
</div>
<div class="parity0 source"><a href="#l541" id="l541">   541</a>             daeSafeCast&lt;domKinematics_newparam::domSIDREF&gt;(kbind-&gt;add(COLLADA_ELEMENT_SIDREF))-&gt;setValue((refscope+ikmsid+&quot;/&quot;+it-&gt;sid).c_str());
</div>
<div class="parity1 source"><a href="#l542" id="l542">   542</a>             double value=0;
</div>
<div class="parity0 source"><a href="#l543" id="l543">   543</a>             double flower=0, fupper=0;
</div>
<div class="parity1 source"><a href="#l544" id="l544">   544</a>             if( !!it-&gt;pjoint-&gt;limits ) {
</div>
<div class="parity0 source"><a href="#l545" id="l545">   545</a>                 flower = it-&gt;pjoint-&gt;limits-&gt;lower;
</div>
<div class="parity1 source"><a href="#l546" id="l546">   546</a>                 fupper = it-&gt;pjoint-&gt;limits-&gt;upper;
</div>
<div class="parity0 source"><a href="#l547" id="l547">   547</a>                 if( flower &gt; 0 || fupper &lt; 0 ) {
</div>
<div class="parity1 source"><a href="#l548" id="l548">   548</a>                     value = 0.5*(flower+fupper);
</div>
<div class="parity0 source"><a href="#l549" id="l549">   549</a>                 }
</div>
<div class="parity1 source"><a href="#l550" id="l550">   550</a>             }
</div>
<div class="parity0 source"><a href="#l551" id="l551">   551</a> 
</div>
<div class="parity1 source"><a href="#l552" id="l552">   552</a>             domKinematics_newparamRef pvalueparam = daeSafeCast&lt;domKinematics_newparam&gt;(_ikmout-&gt;ikm-&gt;add(COLLADA_ELEMENT_NEWPARAM));
</div>
<div class="parity0 source"><a href="#l553" id="l553">   553</a>             pvalueparam-&gt;setSid((sid+string(&quot;_value&quot;)).c_str());
</div>
<div class="parity1 source"><a href="#l554" id="l554">   554</a>             daeSafeCast&lt;domKinematics_newparam::domFloat&gt;(pvalueparam-&gt;add(COLLADA_ELEMENT_FLOAT))-&gt;setValue(value);
</div>
<div class="parity0 source"><a href="#l555" id="l555">   555</a>             _ikmout-&gt;vaxissids.push_back(axis_sids(sid,pvalueparam-&gt;getSid(),kmout-&gt;vaxissids.at(i).jointnodesid));
</div>
<div class="parity1 source"><a href="#l556" id="l556">   556</a>             ++i;
</div>
<div class="parity0 source"><a href="#l557" id="l557">   557</a>         }
</div>
<div class="parity1 source"><a href="#l558" id="l558">   558</a>     }
</div>
<div class="parity0 source"><a href="#l559" id="l559">   559</a> 
</div>
<div class="parity1 source"><a href="#l560" id="l560">   560</a>     virtual boost::shared_ptr&lt;kinematics_model_output&gt; WriteKinematics_model(int id)
</div>
<div class="parity0 source"><a href="#l561" id="l561">   561</a>     {
</div>
<div class="parity1 source"><a href="#l562" id="l562">   562</a>         domKinematics_modelRef kmodel = daeSafeCast&lt;domKinematics_model&gt;(_kinematicsModelsLib-&gt;add(COLLADA_ELEMENT_KINEMATICS_MODEL));
</div>
<div class="parity0 source"><a href="#l563" id="l563">   563</a>         string kmodelid = _ComputeId(str(boost::format(&quot;kmodel%d&quot;)%id));
</div>
<div class="parity1 source"><a href="#l564" id="l564">   564</a>         kmodel-&gt;setId(kmodelid.c_str());
</div>
<div class="parity0 source"><a href="#l565" id="l565">   565</a>         kmodel-&gt;setName(_robot.getName().c_str());
</div>
<div class="parity1 source"><a href="#l566" id="l566">   566</a> 
</div>
<div class="parity0 source"><a href="#l567" id="l567">   567</a>         domKinematics_model_techniqueRef ktec = daeSafeCast&lt;domKinematics_model_technique&gt;(kmodel-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity1 source"><a href="#l568" id="l568">   568</a> 
</div>
<div class="parity0 source"><a href="#l569" id="l569">   569</a>         //  Create root node for the visual scene
</div>
<div class="parity1 source"><a href="#l570" id="l570">   570</a>         domNodeRef pnoderoot = daeSafeCast&lt;domNode&gt;(_scene.vscene-&gt;add(COLLADA_ELEMENT_NODE));
</div>
<div class="parity0 source"><a href="#l571" id="l571">   571</a>         string bodyid = _ComputeId(str(boost::format(&quot;visual%d&quot;)%id));
</div>
<div class="parity1 source"><a href="#l572" id="l572">   572</a>         pnoderoot-&gt;setId(bodyid.c_str());
</div>
<div class="parity0 source"><a href="#l573" id="l573">   573</a>         pnoderoot-&gt;setSid(bodyid.c_str());
</div>
<div class="parity1 source"><a href="#l574" id="l574">   574</a>         pnoderoot-&gt;setName(_robot.getName().c_str());
</div>
<div class="parity0 source"><a href="#l575" id="l575">   575</a> 
</div>
<div class="parity1 source"><a href="#l576" id="l576">   576</a>         //  Declare all the joints
</div>
<div class="parity0 source"><a href="#l577" id="l577">   577</a>         _mapjointindices.clear();
</div>
<div class="parity1 source"><a href="#l578" id="l578">   578</a>         int index=0;
</div>
<div class="parity0 source"><a href="#l579" id="l579">   579</a>         FOREACHC(itj, _robot.joints_) {
</div>
<div class="parity1 source"><a href="#l580" id="l580">   580</a>             _mapjointindices[itj-&gt;second] = index++;
</div>
<div class="parity0 source"><a href="#l581" id="l581">   581</a>         }
</div>
<div class="parity1 source"><a href="#l582" id="l582">   582</a>         _maplinkindices.clear();
</div>
<div class="parity0 source"><a href="#l583" id="l583">   583</a>         index=0;
</div>
<div class="parity1 source"><a href="#l584" id="l584">   584</a>         FOREACHC(itj, _robot.links_) {
</div>
<div class="parity0 source"><a href="#l585" id="l585">   585</a>             _maplinkindices[itj-&gt;second] = index++;
</div>
<div class="parity1 source"><a href="#l586" id="l586">   586</a>         }
</div>
<div class="parity0 source"><a href="#l587" id="l587">   587</a>         _mapmaterialindices.clear();
</div>
<div class="parity1 source"><a href="#l588" id="l588">   588</a>         index=0;
</div>
<div class="parity0 source"><a href="#l589" id="l589">   589</a>         FOREACHC(itj, _robot.materials_) {
</div>
<div class="parity1 source"><a href="#l590" id="l590">   590</a>             _mapmaterialindices[itj-&gt;second] = index++;
</div>
<div class="parity0 source"><a href="#l591" id="l591">   591</a>         }
</div>
<div class="parity1 source"><a href="#l592" id="l592">   592</a> 
</div>
<div class="parity0 source"><a href="#l593" id="l593">   593</a>         double lmin, lmax;
</div>
<div class="parity1 source"><a href="#l594" id="l594">   594</a>         vector&lt;domJointRef&gt; vdomjoints(_robot.joints_.size());
</div>
<div class="parity0 source"><a href="#l595" id="l595">   595</a>         boost::shared_ptr&lt;kinematics_model_output&gt; kmout(new kinematics_model_output());
</div>
<div class="parity1 source"><a href="#l596" id="l596">   596</a>         kmout-&gt;kmodel = kmodel;
</div>
<div class="parity0 source"><a href="#l597" id="l597">   597</a>         kmout-&gt;vaxissids.resize(_robot.joints_.size());
</div>
<div class="parity1 source"><a href="#l598" id="l598">   598</a>         kmout-&gt;vlinksids.resize(_robot.links_.size());
</div>
<div class="parity0 source"><a href="#l599" id="l599">   599</a> 
</div>
<div class="parity1 source"><a href="#l600" id="l600">   600</a>         FOREACHC(itjoint, _robot.joints_) {
</div>
<div class="parity0 source"><a href="#l601" id="l601">   601</a>             boost::shared_ptr&lt;urdf::Joint&gt; pjoint = itjoint-&gt;second;
</div>
<div class="parity1 source"><a href="#l602" id="l602">   602</a>             int index = _mapjointindices[itjoint-&gt;second];
</div>
<div class="parity0 source"><a href="#l603" id="l603">   603</a>             domJointRef pdomjoint = daeSafeCast&lt;domJoint&gt;(ktec-&gt;add(COLLADA_ELEMENT_JOINT));
</div>
<div class="parity1 source"><a href="#l604" id="l604">   604</a>             string jointid = _ComputeId(pjoint-&gt;name);//str(boost::format(&quot;joint%d&quot;)%index);
</div>
<div class="parity0 source"><a href="#l605" id="l605">   605</a>             pdomjoint-&gt;setSid(jointid.c_str() );
</div>
<div class="parity1 source"><a href="#l606" id="l606">   606</a>             pdomjoint-&gt;setName(pjoint-&gt;name.c_str());
</div>
<div class="parity0 source"><a href="#l607" id="l607">   607</a>             domAxis_constraintRef axis;
</div>
<div class="parity1 source"><a href="#l608" id="l608">   608</a>             if( !!pjoint-&gt;limits ) {
</div>
<div class="parity0 source"><a href="#l609" id="l609">   609</a>                 lmin=pjoint-&gt;limits-&gt;lower;
</div>
<div class="parity1 source"><a href="#l610" id="l610">   610</a>                 lmax=pjoint-&gt;limits-&gt;upper;
</div>
<div class="parity0 source"><a href="#l611" id="l611">   611</a>             }
</div>
<div class="parity1 source"><a href="#l612" id="l612">   612</a>             else {
</div>
<div class="parity0 source"><a href="#l613" id="l613">   613</a>                 lmin = lmax = 0;
</div>
<div class="parity1 source"><a href="#l614" id="l614">   614</a>             }
</div>
<div class="parity0 source"><a href="#l615" id="l615">   615</a> 
</div>
<div class="parity1 source"><a href="#l616" id="l616">   616</a>             double fmult = 1.0;
</div>
<div class="parity0 source"><a href="#l617" id="l617">   617</a>             switch(pjoint-&gt;type) {
</div>
<div class="parity1 source"><a href="#l618" id="l618">   618</a>             case urdf::Joint::REVOLUTE:
</div>
<div class="parity0 source"><a href="#l619" id="l619">   619</a>             case urdf::Joint::CONTINUOUS:
</div>
<div class="parity1 source"><a href="#l620" id="l620">   620</a>                 axis = daeSafeCast&lt;domAxis_constraint&gt;(pdomjoint-&gt;add(COLLADA_ELEMENT_REVOLUTE));
</div>
<div class="parity0 source"><a href="#l621" id="l621">   621</a>                 fmult = 180.0f/M_PI;
</div>
<div class="parity1 source"><a href="#l622" id="l622">   622</a>                 lmin*=fmult;
</div>
<div class="parity0 source"><a href="#l623" id="l623">   623</a>                 lmax*=fmult;
</div>
<div class="parity1 source"><a href="#l624" id="l624">   624</a>                 break;
</div>
<div class="parity0 source"><a href="#l625" id="l625">   625</a>             case urdf::Joint::PRISMATIC:
</div>
<div class="parity1 source"><a href="#l626" id="l626">   626</a>                 axis = daeSafeCast&lt;domAxis_constraint&gt;(pdomjoint-&gt;add(COLLADA_ELEMENT_PRISMATIC));
</div>
<div class="parity0 source"><a href="#l627" id="l627">   627</a>                 break;
</div>
<div class="parity1 source"><a href="#l628" id="l628">   628</a>             case urdf::Joint::FIXED:
</div>
<div class="parity0 source"><a href="#l629" id="l629">   629</a>                 axis = daeSafeCast&lt;domAxis_constraint&gt;(pdomjoint-&gt;add(COLLADA_ELEMENT_REVOLUTE));
</div>
<div class="parity1 source"><a href="#l630" id="l630">   630</a>                 lmin = 0;
</div>
<div class="parity0 source"><a href="#l631" id="l631">   631</a>                 lmax = 0;
</div>
<div class="parity1 source"><a href="#l632" id="l632">   632</a>                 fmult = 0;
</div>
<div class="parity0 source"><a href="#l633" id="l633">   633</a>                 break;
</div>
<div class="parity1 source"><a href="#l634" id="l634">   634</a>             default:
</div>
<div class="parity0 source"><a href="#l635" id="l635">   635</a>                 ROS_WARN_STREAM(str(boost::format(&quot;unsupported joint type specified %d&quot;)%(int)pjoint-&gt;type));
</div>
<div class="parity1 source"><a href="#l636" id="l636">   636</a>                 break;
</div>
<div class="parity0 source"><a href="#l637" id="l637">   637</a>             }
</div>
<div class="parity1 source"><a href="#l638" id="l638">   638</a> 
</div>
<div class="parity0 source"><a href="#l639" id="l639">   639</a>             if( !axis ) {
</div>
<div class="parity1 source"><a href="#l640" id="l640">   640</a>                 continue;
</div>
<div class="parity0 source"><a href="#l641" id="l641">   641</a>             }
</div>
<div class="parity1 source"><a href="#l642" id="l642">   642</a> 
</div>
<div class="parity0 source"><a href="#l643" id="l643">   643</a>             int ia = 0;
</div>
<div class="parity1 source"><a href="#l644" id="l644">   644</a>             string axisid = _ComputeId(str(boost::format(&quot;axis%d&quot;)%ia));
</div>
<div class="parity0 source"><a href="#l645" id="l645">   645</a>             axis-&gt;setSid(axisid.c_str());
</div>
<div class="parity1 source"><a href="#l646" id="l646">   646</a>             kmout-&gt;vaxissids.at(index).pjoint = pjoint;
</div>
<div class="parity0 source"><a href="#l647" id="l647">   647</a>             kmout-&gt;vaxissids.at(index).sid = jointid+string(&quot;/&quot;)+axisid;
</div>
<div class="parity1 source"><a href="#l648" id="l648">   648</a>             kmout-&gt;vaxissids.at(index).iaxis = ia;
</div>
<div class="parity0 source"><a href="#l649" id="l649">   649</a>             domAxisRef paxis = daeSafeCast&lt;domAxis&gt;(axis-&gt;add(COLLADA_ELEMENT_AXIS));
</div>
<div class="parity1 source"><a href="#l650" id="l650">   650</a>             paxis-&gt;getValue().setCount(3);
</div>
<div class="parity0 source"><a href="#l651" id="l651">   651</a>             paxis-&gt;getValue()[0] = pjoint-&gt;axis.x;
</div>
<div class="parity1 source"><a href="#l652" id="l652">   652</a>             paxis-&gt;getValue()[1] = pjoint-&gt;axis.y;
</div>
<div class="parity0 source"><a href="#l653" id="l653">   653</a>             paxis-&gt;getValue()[2] = pjoint-&gt;axis.z;
</div>
<div class="parity1 source"><a href="#l654" id="l654">   654</a>             if( pjoint-&gt;type != urdf::Joint::CONTINUOUS ) {
</div>
<div class="parity0 source"><a href="#l655" id="l655">   655</a>                 domJoint_limitsRef plimits = daeSafeCast&lt;domJoint_limits&gt;(axis-&gt;add(COLLADA_TYPE_LIMITS));
</div>
<div class="parity1 source"><a href="#l656" id="l656">   656</a>                 daeSafeCast&lt;domMinmax&gt;(plimits-&gt;add(COLLADA_ELEMENT_MIN))-&gt;getValue() = lmin;
</div>
<div class="parity0 source"><a href="#l657" id="l657">   657</a>                 daeSafeCast&lt;domMinmax&gt;(plimits-&gt;add(COLLADA_ELEMENT_MAX))-&gt;getValue() = lmax;
</div>
<div class="parity1 source"><a href="#l658" id="l658">   658</a>             }
</div>
<div class="parity0 source"><a href="#l659" id="l659">   659</a>             vdomjoints.at(index) = pdomjoint;
</div>
<div class="parity1 source"><a href="#l660" id="l660">   660</a>         }
</div>
<div class="parity0 source"><a href="#l661" id="l661">   661</a> 
</div>
<div class="parity1 source"><a href="#l662" id="l662">   662</a>         LINKOUTPUT childinfo = _WriteLink(_robot.getRoot(), ktec, pnoderoot, kmodel-&gt;getID());
</div>
<div class="parity0 source"><a href="#l663" id="l663">   663</a>         FOREACHC(itused, childinfo.listusedlinks) {
</div>
<div class="parity1 source"><a href="#l664" id="l664">   664</a>             kmout-&gt;vlinksids.at(itused-&gt;first) = itused-&gt;second;
</div>
<div class="parity0 source"><a href="#l665" id="l665">   665</a>         }
</div>
<div class="parity1 source"><a href="#l666" id="l666">   666</a>         FOREACH(itprocessed,childinfo.listprocesseddofs) {
</div>
<div class="parity0 source"><a href="#l667" id="l667">   667</a>             kmout-&gt;vaxissids.at(itprocessed-&gt;first).jointnodesid = itprocessed-&gt;second;
</div>
<div class="parity1 source"><a href="#l668" id="l668">   668</a>         }
</div>
<div class="parity0 source"><a href="#l669" id="l669">   669</a> 
</div>
<div class="parity1 source"><a href="#l670" id="l670">   670</a>         // create the formulas for all mimic joints
</div>
<div class="parity0 source"><a href="#l671" id="l671">   671</a>         FOREACHC(itjoint, _robot.joints_) {
</div>
<div class="parity1 source"><a href="#l672" id="l672">   672</a>             string jointsid = _ComputeId(itjoint-&gt;second-&gt;name);
</div>
<div class="parity0 source"><a href="#l673" id="l673">   673</a>             boost::shared_ptr&lt;urdf::Joint&gt; pjoint = itjoint-&gt;second;
</div>
<div class="parity1 source"><a href="#l674" id="l674">   674</a>             if( !pjoint-&gt;mimic ) {
</div>
<div class="parity0 source"><a href="#l675" id="l675">   675</a>                 continue;
</div>
<div class="parity1 source"><a href="#l676" id="l676">   676</a>             }
</div>
<div class="parity0 source"><a href="#l677" id="l677">   677</a> 
</div>
<div class="parity1 source"><a href="#l678" id="l678">   678</a>             domFormulaRef pf = daeSafeCast&lt;domFormula&gt;(ktec-&gt;add(COLLADA_ELEMENT_FORMULA));
</div>
<div class="parity0 source"><a href="#l679" id="l679">   679</a>             string formulaid = _ComputeId(str(boost::format(&quot;%s_formula&quot;)%jointsid));
</div>
<div class="parity1 source"><a href="#l680" id="l680">   680</a>             pf-&gt;setSid(formulaid.c_str());
</div>
<div class="parity0 source"><a href="#l681" id="l681">   681</a>             domCommon_float_or_paramRef ptarget = daeSafeCast&lt;domCommon_float_or_param&gt;(pf-&gt;add(COLLADA_ELEMENT_TARGET));
</div>
<div class="parity1 source"><a href="#l682" id="l682">   682</a>             string targetjointid = str(boost::format(&quot;%s/%s&quot;)%kmodel-&gt;getID()%jointsid);
</div>
<div class="parity0 source"><a href="#l683" id="l683">   683</a>             daeSafeCast&lt;domCommon_param&gt;(ptarget-&gt;add(COLLADA_TYPE_PARAM))-&gt;setValue(targetjointid.c_str());
</div>
<div class="parity1 source"><a href="#l684" id="l684">   684</a> 
</div>
<div class="parity0 source"><a href="#l685" id="l685">   685</a>             domTechniqueRef pftec = daeSafeCast&lt;domTechnique&gt;(pf-&gt;add(COLLADA_ELEMENT_TECHNIQUE));
</div>
<div class="parity1 source"><a href="#l686" id="l686">   686</a>             pftec-&gt;setProfile(&quot;OpenRAVE&quot;);
</div>
<div class="parity0 source"><a href="#l687" id="l687">   687</a>             // save position equation
</div>
<div class="parity1 source"><a href="#l688" id="l688">   688</a>             {
</div>
<div class="parity0 source"><a href="#l689" id="l689">   689</a>                 daeElementRef poselt = pftec-&gt;add(&quot;equation&quot;);
</div>
<div class="parity1 source"><a href="#l690" id="l690">   690</a>                 poselt-&gt;setAttribute(&quot;type&quot;,&quot;position&quot;);
</div>
<div class="parity0 source"><a href="#l691" id="l691">   691</a>                 // create a const0*joint+const1 formula
</div>
<div class="parity1 source"><a href="#l692" id="l692">   692</a>                 // &lt;apply&gt; &lt;plus/&gt; &lt;apply&gt; &lt;times/&gt; &lt;cn&gt;a&lt;/cn&gt; x &lt;/apply&gt; &lt;cn&gt;b&lt;/cn&gt; &lt;/apply&gt;
</div>
<div class="parity0 source"><a href="#l693" id="l693">   693</a>                 daeElementRef pmath_math = poselt-&gt;add(&quot;math&quot;);
</div>
<div class="parity1 source"><a href="#l694" id="l694">   694</a>                 daeElementRef pmath_apply = pmath_math-&gt;add(&quot;apply&quot;);
</div>
<div class="parity0 source"><a href="#l695" id="l695">   695</a>                 {
</div>
<div class="parity1 source"><a href="#l696" id="l696">   696</a>                     daeElementRef pmath_plus = pmath_apply-&gt;add(&quot;plus&quot;);
</div>
<div class="parity0 source"><a href="#l697" id="l697">   697</a>                     daeElementRef pmath_apply1 = pmath_apply-&gt;add(&quot;apply&quot;);
</div>
<div class="parity1 source"><a href="#l698" id="l698">   698</a>                     {
</div>
<div class="parity0 source"><a href="#l699" id="l699">   699</a>                         daeElementRef pmath_times = pmath_apply1-&gt;add(&quot;times&quot;);
</div>
<div class="parity1 source"><a href="#l700" id="l700">   700</a>                         daeElementRef pmath_const0 = pmath_apply1-&gt;add(&quot;cn&quot;);
</div>
<div class="parity0 source"><a href="#l701" id="l701">   701</a>                         pmath_const0-&gt;setCharData(str(boost::format(&quot;%f&quot;)%pjoint-&gt;mimic-&gt;multiplier));
</div>
<div class="parity1 source"><a href="#l702" id="l702">   702</a>                         daeElementRef pmath_symb = pmath_apply1-&gt;add(&quot;csymbol&quot;);
</div>
<div class="parity0 source"><a href="#l703" id="l703">   703</a>                         pmath_symb-&gt;setAttribute(&quot;encoding&quot;,&quot;COLLADA&quot;);
</div>
<div class="parity1 source"><a href="#l704" id="l704">   704</a>                         pmath_symb-&gt;setCharData(str(boost::format(&quot;%s/%s&quot;)%kmodel-&gt;getID()%_ComputeId(pjoint-&gt;mimic-&gt;joint_name)));
</div>
<div class="parity0 source"><a href="#l705" id="l705">   705</a>                     }
</div>
<div class="parity1 source"><a href="#l706" id="l706">   706</a>                     daeElementRef pmath_const1 = pmath_apply-&gt;add(&quot;cn&quot;);
</div>
<div class="parity0 source"><a href="#l707" id="l707">   707</a>                     pmath_const1-&gt;setCharData(str(boost::format(&quot;%f&quot;)%pjoint-&gt;mimic-&gt;offset));
</div>
<div class="parity1 source"><a href="#l708" id="l708">   708</a>                 }
</div>
<div class="parity0 source"><a href="#l709" id="l709">   709</a>             }
</div>
<div class="parity1 source"><a href="#l710" id="l710">   710</a>             // save first partial derivative
</div>
<div class="parity0 source"><a href="#l711" id="l711">   711</a>             {
</div>
<div class="parity1 source"><a href="#l712" id="l712">   712</a>                 daeElementRef derivelt = pftec-&gt;add(&quot;equation&quot;);
</div>
<div class="parity0 source"><a href="#l713" id="l713">   713</a>                 derivelt-&gt;setAttribute(&quot;type&quot;,&quot;first_partial&quot;);
</div>
<div class="parity1 source"><a href="#l714" id="l714">   714</a>                 derivelt-&gt;setAttribute(&quot;target&quot;,str(boost::format(&quot;%s/%s&quot;)%kmodel-&gt;getID()%_ComputeId(pjoint-&gt;mimic-&gt;joint_name)).c_str());
</div>
<div class="parity0 source"><a href="#l715" id="l715">   715</a>                 daeElementRef pmath_const0 = derivelt-&gt;add(&quot;cn&quot;);
</div>
<div class="parity1 source"><a href="#l716" id="l716">   716</a>                 pmath_const0-&gt;setCharData(str(boost::format(&quot;%f&quot;)%pjoint-&gt;mimic-&gt;multiplier));
</div>
<div class="parity0 source"><a href="#l717" id="l717">   717</a>             }
</div>
<div class="parity1 source"><a href="#l718" id="l718">   718</a>             // save second partial derivative
</div>
<div class="parity0 source"><a href="#l719" id="l719">   719</a>             {
</div>
<div class="parity1 source"><a href="#l720" id="l720">   720</a>                 daeElementRef derivelt = pftec-&gt;add(&quot;equation&quot;);
</div>
<div class="parity0 source"><a href="#l721" id="l721">   721</a>                 derivelt-&gt;setAttribute(&quot;type&quot;,&quot;second_partial&quot;);
</div>
<div class="parity1 source"><a href="#l722" id="l722">   722</a>                 derivelt-&gt;setAttribute(&quot;target&quot;,str(boost::format(&quot;%s/%s&quot;)%kmodel-&gt;getID()%_ComputeId(pjoint-&gt;mimic-&gt;joint_name)).c_str());
</div>
<div class="parity0 source"><a href="#l723" id="l723">   723</a>                 daeElementRef pmath_const0 = derivelt-&gt;add(&quot;cn&quot;);
</div>
<div class="parity1 source"><a href="#l724" id="l724">   724</a>                 pmath_const0-&gt;setCharData(&quot;0&quot;);
</div>
<div class="parity0 source"><a href="#l725" id="l725">   725</a>             }
</div>
<div class="parity1 source"><a href="#l726" id="l726">   726</a> 
</div>
<div class="parity0 source"><a href="#l727" id="l727">   727</a>             {
</div>
<div class="parity1 source"><a href="#l728" id="l728">   728</a>                 domFormula_techniqueRef pfcommontec = daeSafeCast&lt;domFormula_technique&gt;(pf-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity0 source"><a href="#l729" id="l729">   729</a>                 // create a const0*joint+const1 formula
</div>
<div class="parity1 source"><a href="#l730" id="l730">   730</a>                 // &lt;apply&gt; &lt;plus/&gt; &lt;apply&gt; &lt;times/&gt; &lt;cn&gt;a&lt;/cn&gt; x &lt;/apply&gt; &lt;cn&gt;b&lt;/cn&gt; &lt;/apply&gt;
</div>
<div class="parity0 source"><a href="#l731" id="l731">   731</a>                 daeElementRef pmath_math = pfcommontec-&gt;add(&quot;math&quot;);
</div>
<div class="parity1 source"><a href="#l732" id="l732">   732</a>                 daeElementRef pmath_apply = pmath_math-&gt;add(&quot;apply&quot;);
</div>
<div class="parity0 source"><a href="#l733" id="l733">   733</a>                 {
</div>
<div class="parity1 source"><a href="#l734" id="l734">   734</a>                     daeElementRef pmath_plus = pmath_apply-&gt;add(&quot;plus&quot;);
</div>
<div class="parity0 source"><a href="#l735" id="l735">   735</a>                     daeElementRef pmath_apply1 = pmath_apply-&gt;add(&quot;apply&quot;);
</div>
<div class="parity1 source"><a href="#l736" id="l736">   736</a>                     {
</div>
<div class="parity0 source"><a href="#l737" id="l737">   737</a>                         daeElementRef pmath_times = pmath_apply1-&gt;add(&quot;times&quot;);
</div>
<div class="parity1 source"><a href="#l738" id="l738">   738</a>                         daeElementRef pmath_const0 = pmath_apply1-&gt;add(&quot;cn&quot;);
</div>
<div class="parity0 source"><a href="#l739" id="l739">   739</a>                         pmath_const0-&gt;setCharData(str(boost::format(&quot;%f&quot;)%pjoint-&gt;mimic-&gt;multiplier));
</div>
<div class="parity1 source"><a href="#l740" id="l740">   740</a>                         daeElementRef pmath_symb = pmath_apply1-&gt;add(&quot;csymbol&quot;);
</div>
<div class="parity0 source"><a href="#l741" id="l741">   741</a>                         pmath_symb-&gt;setAttribute(&quot;encoding&quot;,&quot;COLLADA&quot;);
</div>
<div class="parity1 source"><a href="#l742" id="l742">   742</a>                         pmath_symb-&gt;setCharData(str(boost::format(&quot;%s/%s&quot;)%kmodel-&gt;getID()%_ComputeId(pjoint-&gt;mimic-&gt;joint_name)));
</div>
<div class="parity0 source"><a href="#l743" id="l743">   743</a>                     }
</div>
<div class="parity1 source"><a href="#l744" id="l744">   744</a>                     daeElementRef pmath_const1 = pmath_apply-&gt;add(&quot;cn&quot;);
</div>
<div class="parity0 source"><a href="#l745" id="l745">   745</a>                     pmath_const1-&gt;setCharData(str(boost::format(&quot;%f&quot;)%pjoint-&gt;mimic-&gt;offset));
</div>
<div class="parity1 source"><a href="#l746" id="l746">   746</a>                 }
</div>
<div class="parity0 source"><a href="#l747" id="l747">   747</a>             }
</div>
<div class="parity1 source"><a href="#l748" id="l748">   748</a>         }
</div>
<div class="parity0 source"><a href="#l749" id="l749">   749</a> 
</div>
<div class="parity1 source"><a href="#l750" id="l750">   750</a>         return kmout;
</div>
<div class="parity0 source"><a href="#l751" id="l751">   751</a>     }
</div>
<div class="parity1 source"><a href="#l752" id="l752">   752</a> 
</div>
<div class="parity0 source"><a href="#l753" id="l753">   753</a>     /// \brief Write link of a kinematic body
</div>
<div class="parity1 source"><a href="#l754" id="l754">   754</a>     ///
</div>
<div class="parity0 source"><a href="#l755" id="l755">   755</a>     /// \param link Link to write
</div>
<div class="parity1 source"><a href="#l756" id="l756">   756</a>     /// \param pkinparent Kinbody parent
</div>
<div class="parity0 source"><a href="#l757" id="l757">   757</a>     /// \param pnodeparent Node parent
</div>
<div class="parity1 source"><a href="#l758" id="l758">   758</a>     /// \param strModelUri
</div>
<div class="parity0 source"><a href="#l759" id="l759">   759</a>     virtual LINKOUTPUT _WriteLink(boost::shared_ptr&lt;const urdf::Link&gt; plink, daeElementRef pkinparent, domNodeRef pnodeparent, const string&amp; strModelUri)
</div>
<div class="parity1 source"><a href="#l760" id="l760">   760</a>     {
</div>
<div class="parity0 source"><a href="#l761" id="l761">   761</a>         LINKOUTPUT out;
</div>
<div class="parity1 source"><a href="#l762" id="l762">   762</a>         int linkindex = _maplinkindices[plink];
</div>
<div class="parity0 source"><a href="#l763" id="l763">   763</a>         string linksid = _ComputeId(plink-&gt;name);
</div>
<div class="parity1 source"><a href="#l764" id="l764">   764</a>         domLinkRef pdomlink = daeSafeCast&lt;domLink&gt;(pkinparent-&gt;add(COLLADA_ELEMENT_LINK));
</div>
<div class="parity0 source"><a href="#l765" id="l765">   765</a>         pdomlink-&gt;setName(plink-&gt;name.c_str());
</div>
<div class="parity1 source"><a href="#l766" id="l766">   766</a>         pdomlink-&gt;setSid(linksid.c_str());
</div>
<div class="parity0 source"><a href="#l767" id="l767">   767</a> 
</div>
<div class="parity1 source"><a href="#l768" id="l768">   768</a>         domNodeRef pnode = daeSafeCast&lt;domNode&gt;(pnodeparent-&gt;add(COLLADA_ELEMENT_NODE));
</div>
<div class="parity0 source"><a href="#l769" id="l769">   769</a>         string nodeid = _ComputeId(str(boost::format(&quot;v%s_node%d&quot;)%strModelUri%linkindex));
</div>
<div class="parity1 source"><a href="#l770" id="l770">   770</a>         pnode-&gt;setId( nodeid.c_str() );
</div>
<div class="parity0 source"><a href="#l771" id="l771">   771</a>         string nodesid = _ComputeId(str(boost::format(&quot;node%d&quot;)%linkindex));
</div>
<div class="parity1 source"><a href="#l772" id="l772">   772</a>         pnode-&gt;setSid(nodesid.c_str());
</div>
<div class="parity0 source"><a href="#l773" id="l773">   773</a>         pnode-&gt;setName(plink-&gt;name.c_str());
</div>
<div class="parity1 source"><a href="#l774" id="l774">   774</a> 
</div>
<div class="parity0 source"><a href="#l775" id="l775">   775</a>         boost::shared_ptr&lt;urdf::Geometry&gt; geometry;
</div>
<div class="parity1 source"><a href="#l776" id="l776">   776</a>         boost::shared_ptr&lt;urdf::Material&gt; material;
</div>
<div class="parity0 source"><a href="#l777" id="l777">   777</a>         urdf::Pose geometry_origin;
</div>
<div class="parity1 source"><a href="#l778" id="l778">   778</a>         if( !!plink-&gt;visual ) {
</div>
<div class="parity0 source"><a href="#l779" id="l779">   779</a>             geometry = plink-&gt;visual-&gt;geometry;
</div>
<div class="parity1 source"><a href="#l780" id="l780">   780</a>             material = plink-&gt;visual-&gt;material;
</div>
<div class="parity0 source"><a href="#l781" id="l781">   781</a>             geometry_origin = plink-&gt;visual-&gt;origin;
</div>
<div class="parity1 source"><a href="#l782" id="l782">   782</a>         }
</div>
<div class="parity0 source"><a href="#l783" id="l783">   783</a>         else if( !!plink-&gt;collision ) {
</div>
<div class="parity1 source"><a href="#l784" id="l784">   784</a>             geometry = plink-&gt;collision-&gt;geometry;
</div>
<div class="parity0 source"><a href="#l785" id="l785">   785</a>             geometry_origin = plink-&gt;collision-&gt;origin;
</div>
<div class="parity1 source"><a href="#l786" id="l786">   786</a>         }
</div>
<div class="parity0 source"><a href="#l787" id="l787">   787</a> 
</div>
<div class="parity1 source"><a href="#l788" id="l788">   788</a>         if( !!geometry ) {
</div>
<div class="parity0 source"><a href="#l789" id="l789">   789</a>             int igeom = 0;
</div>
<div class="parity1 source"><a href="#l790" id="l790">   790</a>             string geomid = _ComputeId(str(boost::format(&quot;g%s_%s_geom%d&quot;)%strModelUri%linksid%igeom));
</div>
<div class="parity0 source"><a href="#l791" id="l791">   791</a>             domGeometryRef pdomgeom = _WriteGeometry(geometry, geomid);
</div>
<div class="parity1 source"><a href="#l792" id="l792">   792</a>             domInstance_geometryRef pinstgeom = daeSafeCast&lt;domInstance_geometry&gt;(pnode-&gt;add(COLLADA_ELEMENT_INSTANCE_GEOMETRY));
</div>
<div class="parity0 source"><a href="#l793" id="l793">   793</a>             pinstgeom-&gt;setUrl((string(&quot;#&quot;)+geomid).c_str());
</div>
<div class="parity1 source"><a href="#l794" id="l794">   794</a> 
</div>
<div class="parity0 source"><a href="#l795" id="l795">   795</a>             // material
</div>
<div class="parity1 source"><a href="#l796" id="l796">   796</a>             _WriteMaterial(pdomgeom-&gt;getID(), material);
</div>
<div class="parity0 source"><a href="#l797" id="l797">   797</a>             domBind_materialRef pmat = daeSafeCast&lt;domBind_material&gt;(pinstgeom-&gt;add(COLLADA_ELEMENT_BIND_MATERIAL));
</div>
<div class="parity1 source"><a href="#l798" id="l798">   798</a>             domBind_material::domTechnique_commonRef pmattec = daeSafeCast&lt;domBind_material::domTechnique_common&gt;(pmat-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity0 source"><a href="#l799" id="l799">   799</a>             domInstance_materialRef pinstmat = daeSafeCast&lt;domInstance_material&gt;(pmattec-&gt;add(COLLADA_ELEMENT_INSTANCE_MATERIAL));
</div>
<div class="parity1 source"><a href="#l800" id="l800">   800</a>             pinstmat-&gt;setTarget(xsAnyURI(*pdomgeom, string(&quot;#&quot;)+geomid+string(&quot;_mat&quot;)));
</div>
<div class="parity0 source"><a href="#l801" id="l801">   801</a>             pinstmat-&gt;setSymbol(&quot;mat0&quot;);
</div>
<div class="parity1 source"><a href="#l802" id="l802">   802</a>         }
</div>
<div class="parity0 source"><a href="#l803" id="l803">   803</a> 
</div>
<div class="parity1 source"><a href="#l804" id="l804">   804</a>         _WriteTransformation(pnode, geometry_origin);
</div>
<div class="parity0 source"><a href="#l805" id="l805">   805</a>         urdf::Pose geometry_origin_inv = _poseInverse(geometry_origin);
</div>
<div class="parity1 source"><a href="#l806" id="l806">   806</a>         
</div>
<div class="parity0 source"><a href="#l807" id="l807">   807</a>         // process all children
</div>
<div class="parity1 source"><a href="#l808" id="l808">   808</a>         FOREACHC(itjoint, plink-&gt;child_joints) {
</div>
<div class="parity0 source"><a href="#l809" id="l809">   809</a>             boost::shared_ptr&lt;urdf::Joint&gt; pjoint = *itjoint;
</div>
<div class="parity1 source"><a href="#l810" id="l810">   810</a>             int index = _mapjointindices[pjoint];
</div>
<div class="parity0 source"><a href="#l811" id="l811">   811</a> 
</div>
<div class="parity1 source"><a href="#l812" id="l812">   812</a>             // &lt;attachment_full joint=&quot;k1/joint0&quot;&gt;
</div>
<div class="parity0 source"><a href="#l813" id="l813">   813</a>             domLink::domAttachment_fullRef attachment_full = daeSafeCast&lt;domLink::domAttachment_full&gt;(pdomlink-&gt;add(COLLADA_ELEMENT_ATTACHMENT_FULL));
</div>
<div class="parity1 source"><a href="#l814" id="l814">   814</a>             string jointid = str(boost::format(&quot;%s/%s&quot;)%strModelUri%_ComputeId(pjoint-&gt;name));
</div>
<div class="parity0 source"><a href="#l815" id="l815">   815</a>             attachment_full-&gt;setJoint(jointid.c_str());
</div>
<div class="parity1 source"><a href="#l816" id="l816">   816</a> 
</div>
<div class="parity0 source"><a href="#l817" id="l817">   817</a>             LINKOUTPUT childinfo = _WriteLink(_robot.getLink(pjoint-&gt;child_link_name), attachment_full, pnode, strModelUri);
</div>
<div class="parity1 source"><a href="#l818" id="l818">   818</a>             FOREACH(itused,childinfo.listusedlinks) {
</div>
<div class="parity0 source"><a href="#l819" id="l819">   819</a>                 out.listusedlinks.push_back(make_pair(itused-&gt;first,linksid+string(&quot;/&quot;)+itused-&gt;second));
</div>
<div class="parity1 source"><a href="#l820" id="l820">   820</a>             }
</div>
<div class="parity0 source"><a href="#l821" id="l821">   821</a>             FOREACH(itprocessed,childinfo.listprocesseddofs) {
</div>
<div class="parity1 source"><a href="#l822" id="l822">   822</a>                 out.listprocesseddofs.push_back(make_pair(itprocessed-&gt;first,nodesid+string(&quot;/&quot;)+itprocessed-&gt;second));
</div>
<div class="parity0 source"><a href="#l823" id="l823">   823</a>             }
</div>
<div class="parity1 source"><a href="#l824" id="l824">   824</a> 
</div>
<div class="parity0 source"><a href="#l825" id="l825">   825</a>             // rotate/translate elements
</div>
<div class="parity1 source"><a href="#l826" id="l826">   826</a>             string jointnodesid = _ComputeId(str(boost::format(&quot;node_%s_axis0&quot;)%pjoint-&gt;name));
</div>
<div class="parity0 source"><a href="#l827" id="l827">   827</a>             switch(pjoint-&gt;type) {
</div>
<div class="parity1 source"><a href="#l828" id="l828">   828</a>             case urdf::Joint::REVOLUTE:
</div>
<div class="parity0 source"><a href="#l829" id="l829">   829</a>             case urdf::Joint::CONTINUOUS:
</div>
<div class="parity1 source"><a href="#l830" id="l830">   830</a>             case urdf::Joint::FIXED: {
</div>
<div class="parity0 source"><a href="#l831" id="l831">   831</a>                 domRotateRef protate = daeSafeCast&lt;domRotate&gt;(childinfo.pnode-&gt;add(COLLADA_ELEMENT_ROTATE,0));
</div>
<div class="parity1 source"><a href="#l832" id="l832">   832</a>                 protate-&gt;setSid(jointnodesid.c_str());
</div>
<div class="parity0 source"><a href="#l833" id="l833">   833</a>                 protate-&gt;getValue().setCount(4);
</div>
<div class="parity1 source"><a href="#l834" id="l834">   834</a>                 protate-&gt;getValue()[0] = pjoint-&gt;axis.x;
</div>
<div class="parity0 source"><a href="#l835" id="l835">   835</a>                 protate-&gt;getValue()[1] = pjoint-&gt;axis.y;
</div>
<div class="parity1 source"><a href="#l836" id="l836">   836</a>                 protate-&gt;getValue()[2] = pjoint-&gt;axis.z;
</div>
<div class="parity0 source"><a href="#l837" id="l837">   837</a>                 protate-&gt;getValue()[3] = 0;
</div>
<div class="parity1 source"><a href="#l838" id="l838">   838</a>                 break;
</div>
<div class="parity0 source"><a href="#l839" id="l839">   839</a>             }
</div>
<div class="parity1 source"><a href="#l840" id="l840">   840</a>             case urdf::Joint::PRISMATIC: {
</div>
<div class="parity0 source"><a href="#l841" id="l841">   841</a>                 domTranslateRef ptrans = daeSafeCast&lt;domTranslate&gt;(childinfo.pnode-&gt;add(COLLADA_ELEMENT_TRANSLATE,0));
</div>
<div class="parity1 source"><a href="#l842" id="l842">   842</a>                 ptrans-&gt;setSid(jointnodesid.c_str());
</div>
<div class="parity0 source"><a href="#l843" id="l843">   843</a>                 ptrans-&gt;getValue().setCount(3);
</div>
<div class="parity1 source"><a href="#l844" id="l844">   844</a>                 ptrans-&gt;getValue()[0] = 0;
</div>
<div class="parity0 source"><a href="#l845" id="l845">   845</a>                 ptrans-&gt;getValue()[1] = 0;
</div>
<div class="parity1 source"><a href="#l846" id="l846">   846</a>                 ptrans-&gt;getValue()[2] = 0;
</div>
<div class="parity0 source"><a href="#l847" id="l847">   847</a>                 break;
</div>
<div class="parity1 source"><a href="#l848" id="l848">   848</a>             }
</div>
<div class="parity0 source"><a href="#l849" id="l849">   849</a>             default:
</div>
<div class="parity1 source"><a href="#l850" id="l850">   850</a>                 ROS_WARN_STREAM(str(boost::format(&quot;unsupported joint type specified %d&quot;)%(int)pjoint-&gt;type));
</div>
<div class="parity0 source"><a href="#l851" id="l851">   851</a>                 break;
</div>
<div class="parity1 source"><a href="#l852" id="l852">   852</a>             }
</div>
<div class="parity0 source"><a href="#l853" id="l853">   853</a>             
</div>
<div class="parity1 source"><a href="#l854" id="l854">   854</a>             _WriteTransformation(attachment_full, pjoint-&gt;parent_to_joint_origin_transform);
</div>
<div class="parity0 source"><a href="#l855" id="l855">   855</a>             _WriteTransformation(childinfo.pnode, pjoint-&gt;parent_to_joint_origin_transform);
</div>
<div class="parity1 source"><a href="#l856" id="l856">   856</a>             _WriteTransformation(childinfo.pnode, geometry_origin_inv); // have to do multiply by inverse since geometry transformation is not part of hierarchy
</div>
<div class="parity0 source"><a href="#l857" id="l857">   857</a>             out.listprocesseddofs.push_back(make_pair(index,string(childinfo.pnode-&gt;getSid())+string(&quot;/&quot;)+jointnodesid));
</div>
<div class="parity1 source"><a href="#l858" id="l858">   858</a>             // &lt;/attachment_full&gt;
</div>
<div class="parity0 source"><a href="#l859" id="l859">   859</a>         }
</div>
<div class="parity1 source"><a href="#l860" id="l860">   860</a> 
</div>
<div class="parity0 source"><a href="#l861" id="l861">   861</a>         out.listusedlinks.push_back(make_pair(linkindex,linksid));
</div>
<div class="parity1 source"><a href="#l862" id="l862">   862</a>         out.plink = pdomlink;
</div>
<div class="parity0 source"><a href="#l863" id="l863">   863</a>         out.pnode = pnode;
</div>
<div class="parity1 source"><a href="#l864" id="l864">   864</a>         return  out;
</div>
<div class="parity0 source"><a href="#l865" id="l865">   865</a>     }
</div>
<div class="parity1 source"><a href="#l866" id="l866">   866</a> 
</div>
<div class="parity0 source"><a href="#l867" id="l867">   867</a>     domGeometryRef _WriteGeometry(boost::shared_ptr&lt;urdf::Geometry&gt; geometry, const std::string&amp; geometry_id)
</div>
<div class="parity1 source"><a href="#l868" id="l868">   868</a>     {
</div>
<div class="parity0 source"><a href="#l869" id="l869">   869</a>         domGeometryRef cgeometry = daeSafeCast&lt;domGeometry&gt;(_geometriesLib-&gt;add(COLLADA_ELEMENT_GEOMETRY));
</div>
<div class="parity1 source"><a href="#l870" id="l870">   870</a>         cgeometry-&gt;setId(geometry_id.c_str());
</div>
<div class="parity0 source"><a href="#l871" id="l871">   871</a>         switch (geometry-&gt;type) {
</div>
<div class="parity1 source"><a href="#l872" id="l872">   872</a>         case urdf::Geometry::MESH: {
</div>
<div class="parity0 source"><a href="#l873" id="l873">   873</a>             urdf::Mesh* urdf_mesh = (urdf::Mesh*) geometry.get();
</div>
<div class="parity1 source"><a href="#l874" id="l874">   874</a>             _loadMesh(urdf_mesh-&gt;filename, cgeometry, urdf_mesh-&gt;scale);
</div>
<div class="parity0 source"><a href="#l875" id="l875">   875</a>             break;
</div>
<div class="parity1 source"><a href="#l876" id="l876">   876</a>         }
</div>
<div class="parity0 source"><a href="#l877" id="l877">   877</a>         case urdf::Geometry::SPHERE: {
</div>
<div class="parity1 source"><a href="#l878" id="l878">   878</a>             ROS_WARN_STREAM(str(boost::format(&quot;cannot export sphere geometries yet! %s&quot;)%geometry_id));
</div>
<div class="parity0 source"><a href="#l879" id="l879">   879</a>             break;
</div>
<div class="parity1 source"><a href="#l880" id="l880">   880</a>         }
</div>
<div class="parity0 source"><a href="#l881" id="l881">   881</a>         case urdf::Geometry::BOX: {
</div>
<div class="parity1 source"><a href="#l882" id="l882">   882</a>             ROS_WARN_STREAM(str(boost::format(&quot;cannot export box geometries yet! %s&quot;)%geometry_id));
</div>
<div class="parity0 source"><a href="#l883" id="l883">   883</a>             break;
</div>
<div class="parity1 source"><a href="#l884" id="l884">   884</a>         }
</div>
<div class="parity0 source"><a href="#l885" id="l885">   885</a>         case urdf::Geometry::CYLINDER: {
</div>
<div class="parity1 source"><a href="#l886" id="l886">   886</a>             ROS_WARN_STREAM(str(boost::format(&quot;cannot export cylinder geometries yet! %s&quot;)%geometry_id));
</div>
<div class="parity0 source"><a href="#l887" id="l887">   887</a>             break;
</div>
<div class="parity1 source"><a href="#l888" id="l888">   888</a>         }
</div>
<div class="parity0 source"><a href="#l889" id="l889">   889</a>         default: {
</div>
<div class="parity1 source"><a href="#l890" id="l890">   890</a>             throw ColladaUrdfException(str(boost::format(&quot;undefined geometry type %d, name %s&quot;)%(int)geometry-&gt;type%geometry_id));
</div>
<div class="parity0 source"><a href="#l891" id="l891">   891</a>         }
</div>
<div class="parity1 source"><a href="#l892" id="l892">   892</a>         }
</div>
<div class="parity0 source"><a href="#l893" id="l893">   893</a>         return cgeometry;
</div>
<div class="parity1 source"><a href="#l894" id="l894">   894</a>     }
</div>
<div class="parity0 source"><a href="#l895" id="l895">   895</a> 
</div>
<div class="parity1 source"><a href="#l896" id="l896">   896</a>     void _WriteMaterial(const string&amp; geometry_id, boost::shared_ptr&lt;urdf::Material&gt; material)
</div>
<div class="parity0 source"><a href="#l897" id="l897">   897</a>     {
</div>
<div class="parity1 source"><a href="#l898" id="l898">   898</a>         string effid = geometry_id+string(&quot;_eff&quot;);
</div>
<div class="parity0 source"><a href="#l899" id="l899">   899</a>         string matid = geometry_id+string(&quot;_mat&quot;);
</div>
<div class="parity1 source"><a href="#l900" id="l900">   900</a>         domMaterialRef pdommat = daeSafeCast&lt;domMaterial&gt;(_materialsLib-&gt;add(COLLADA_ELEMENT_MATERIAL));
</div>
<div class="parity0 source"><a href="#l901" id="l901">   901</a>         pdommat-&gt;setId(matid.c_str());
</div>
<div class="parity1 source"><a href="#l902" id="l902">   902</a>         domInstance_effectRef pdominsteff = daeSafeCast&lt;domInstance_effect&gt;(pdommat-&gt;add(COLLADA_ELEMENT_INSTANCE_EFFECT));
</div>
<div class="parity0 source"><a href="#l903" id="l903">   903</a>         pdominsteff-&gt;setUrl((string(&quot;#&quot;)+effid).c_str());
</div>
<div class="parity1 source"><a href="#l904" id="l904">   904</a> 
</div>
<div class="parity0 source"><a href="#l905" id="l905">   905</a>         urdf::Color ambient, diffuse;
</div>
<div class="parity1 source"><a href="#l906" id="l906">   906</a>         ambient.init(&quot;0.1 0.1 0.1 0&quot;);
</div>
<div class="parity0 source"><a href="#l907" id="l907">   907</a>         diffuse.init(&quot;1 1 1 0&quot;);
</div>
<div class="parity1 source"><a href="#l908" id="l908">   908</a> 
</div>
<div class="parity0 source"><a href="#l909" id="l909">   909</a>         if( !!material ) {
</div>
<div class="parity1 source"><a href="#l910" id="l910">   910</a>             ambient.r = diffuse.r = material-&gt;color.r;
</div>
<div class="parity0 source"><a href="#l911" id="l911">   911</a>             ambient.g = diffuse.g = material-&gt;color.g;
</div>
<div class="parity1 source"><a href="#l912" id="l912">   912</a>             ambient.b = diffuse.b = material-&gt;color.b;
</div>
<div class="parity0 source"><a href="#l913" id="l913">   913</a>             ambient.a = diffuse.a = material-&gt;color.a;
</div>
<div class="parity1 source"><a href="#l914" id="l914">   914</a>         }
</div>
<div class="parity0 source"><a href="#l915" id="l915">   915</a> 
</div>
<div class="parity1 source"><a href="#l916" id="l916">   916</a>         domEffectRef effect = _WriteEffect(geometry_id, ambient, diffuse);
</div>
<div class="parity0 source"><a href="#l917" id="l917">   917</a> 
</div>
<div class="parity1 source"><a href="#l918" id="l918">   918</a>         // &lt;material id=&quot;g1.link0.geom0.eff&quot;&gt;
</div>
<div class="parity0 source"><a href="#l919" id="l919">   919</a>         domMaterialRef dommaterial = daeSafeCast&lt;domMaterial&gt;(_materialsLib-&gt;add(COLLADA_ELEMENT_MATERIAL));
</div>
<div class="parity1 source"><a href="#l920" id="l920">   920</a>         string material_id = geometry_id + string(&quot;_mat&quot;);
</div>
<div class="parity0 source"><a href="#l921" id="l921">   921</a>         dommaterial-&gt;setId(material_id.c_str());
</div>
<div class="parity1 source"><a href="#l922" id="l922">   922</a>         {
</div>
<div class="parity0 source"><a href="#l923" id="l923">   923</a>             // &lt;instance_effect url=&quot;#g1.link0.geom0.eff&quot;/&gt;
</div>
<div class="parity1 source"><a href="#l924" id="l924">   924</a>             domInstance_effectRef instance_effect = daeSafeCast&lt;domInstance_effect&gt;(dommaterial-&gt;add(COLLADA_ELEMENT_INSTANCE_EFFECT));
</div>
<div class="parity0 source"><a href="#l925" id="l925">   925</a>             string effect_id(effect-&gt;getId());
</div>
<div class="parity1 source"><a href="#l926" id="l926">   926</a>             instance_effect-&gt;setUrl((string(&quot;#&quot;) + effect_id).c_str());
</div>
<div class="parity0 source"><a href="#l927" id="l927">   927</a>         }
</div>
<div class="parity1 source"><a href="#l928" id="l928">   928</a>         // &lt;/material&gt;
</div>
<div class="parity0 source"><a href="#l929" id="l929">   929</a> 
</div>
<div class="parity1 source"><a href="#l930" id="l930">   930</a>         domEffectRef pdomeff = _WriteEffect(effid, ambient, diffuse);
</div>
<div class="parity0 source"><a href="#l931" id="l931">   931</a>     }
</div>
<div class="parity1 source"><a href="#l932" id="l932">   932</a> 
</div>
<div class="parity0 source"><a href="#l933" id="l933">   933</a>     void _loadMesh(std::string const&amp; filename, domGeometryRef pdomgeom, const urdf::Vector3&amp; scale)
</div>
<div class="parity1 source"><a href="#l934" id="l934">   934</a>     {        
</div>
<div class="parity0 source"><a href="#l935" id="l935">   935</a>         const aiScene* scene = _importer.ReadFile(filename, aiProcess_SortByPType|aiProcess_Triangulate);//|aiProcess_GenNormals|aiProcess_GenUVCoords|aiProcess_FlipUVs);
</div>
<div class="parity1 source"><a href="#l936" id="l936">   936</a>         if( !scene ) {
</div>
<div class="parity0 source"><a href="#l937" id="l937">   937</a>             ROS_WARN(&quot;failed to load resource %s&quot;,filename.c_str());
</div>
<div class="parity1 source"><a href="#l938" id="l938">   938</a>             return;
</div>
<div class="parity0 source"><a href="#l939" id="l939">   939</a>         }
</div>
<div class="parity1 source"><a href="#l940" id="l940">   940</a>         if( !scene-&gt;mRootNode ) {
</div>
<div class="parity0 source"><a href="#l941" id="l941">   941</a>             ROS_WARN(&quot;resource %s has no data&quot;,filename.c_str());
</div>
<div class="parity1 source"><a href="#l942" id="l942">   942</a>             return;
</div>
<div class="parity0 source"><a href="#l943" id="l943">   943</a>         }
</div>
<div class="parity1 source"><a href="#l944" id="l944">   944</a>         if (!scene-&gt;HasMeshes()) {
</div>
<div class="parity0 source"><a href="#l945" id="l945">   945</a>             ROS_WARN_STREAM(str(boost::format(&quot;No meshes found in file %s&quot;)%filename));
</div>
<div class="parity1 source"><a href="#l946" id="l946">   946</a>             return;
</div>
<div class="parity0 source"><a href="#l947" id="l947">   947</a>         }
</div>
<div class="parity1 source"><a href="#l948" id="l948">   948</a>         domMeshRef pdommesh = daeSafeCast&lt;domMesh&gt;(pdomgeom-&gt;add(COLLADA_ELEMENT_MESH));
</div>
<div class="parity0 source"><a href="#l949" id="l949">   949</a>         domSourceRef pvertsource = daeSafeCast&lt;domSource&gt;(pdommesh-&gt;add(COLLADA_ELEMENT_SOURCE));
</div>
<div class="parity1 source"><a href="#l950" id="l950">   950</a>         domAccessorRef pacc;
</div>
<div class="parity0 source"><a href="#l951" id="l951">   951</a>         domFloat_arrayRef parray;
</div>
<div class="parity1 source"><a href="#l952" id="l952">   952</a>         {
</div>
<div class="parity0 source"><a href="#l953" id="l953">   953</a>             pvertsource-&gt;setId(str(boost::format(&quot;%s_positions&quot;)%pdomgeom-&gt;getID()).c_str());
</div>
<div class="parity1 source"><a href="#l954" id="l954">   954</a> 
</div>
<div class="parity0 source"><a href="#l955" id="l955">   955</a>             parray = daeSafeCast&lt;domFloat_array&gt;(pvertsource-&gt;add(COLLADA_ELEMENT_FLOAT_ARRAY));
</div>
<div class="parity1 source"><a href="#l956" id="l956">   956</a>             parray-&gt;setId(str(boost::format(&quot;%s_positions-array&quot;)%pdomgeom-&gt;getID()).c_str());
</div>
<div class="parity0 source"><a href="#l957" id="l957">   957</a>             parray-&gt;setDigits(6); // 6 decimal places
</div>
<div class="parity1 source"><a href="#l958" id="l958">   958</a> 
</div>
<div class="parity0 source"><a href="#l959" id="l959">   959</a>             domSource::domTechnique_commonRef psourcetec = daeSafeCast&lt;domSource::domTechnique_common&gt;(pvertsource-&gt;add(COLLADA_ELEMENT_TECHNIQUE_COMMON));
</div>
<div class="parity1 source"><a href="#l960" id="l960">   960</a>             pacc = daeSafeCast&lt;domAccessor&gt;(psourcetec-&gt;add(COLLADA_ELEMENT_ACCESSOR));
</div>
<div class="parity0 source"><a href="#l961" id="l961">   961</a>             pacc-&gt;setSource(xsAnyURI(*parray, string(&quot;#&quot;)+string(parray-&gt;getID())));
</div>
<div class="parity1 source"><a href="#l962" id="l962">   962</a>             pacc-&gt;setStride(3);
</div>
<div class="parity0 source"><a href="#l963" id="l963">   963</a> 
</div>
<div class="parity1 source"><a href="#l964" id="l964">   964</a>             domParamRef px = daeSafeCast&lt;domParam&gt;(pacc-&gt;add(COLLADA_ELEMENT_PARAM));
</div>
<div class="parity0 source"><a href="#l965" id="l965">   965</a>             px-&gt;setName(&quot;X&quot;); px-&gt;setType(&quot;float&quot;);
</div>
<div class="parity1 source"><a href="#l966" id="l966">   966</a>             domParamRef py = daeSafeCast&lt;domParam&gt;(pacc-&gt;add(COLLADA_ELEMENT_PARAM));
</div>
<div class="parity0 source"><a href="#l967" id="l967">   967</a>             py-&gt;setName(&quot;Y&quot;); py-&gt;setType(&quot;float&quot;);
</div>
<div class="parity1 source"><a href="#l968" id="l968">   968</a>             domParamRef pz = daeSafeCast&lt;domParam&gt;(pacc-&gt;add(COLLADA_ELEMENT_PARAM));
</div>
<div class="parity0 source"><a href="#l969" id="l969">   969</a>             pz-&gt;setName(&quot;Z&quot;); pz-&gt;setType(&quot;float&quot;);
</div>
<div class="parity1 source"><a href="#l970" id="l970">   970</a>         }
</div>
<div class="parity0 source"><a href="#l971" id="l971">   971</a>         domVerticesRef pverts = daeSafeCast&lt;domVertices&gt;(pdommesh-&gt;add(COLLADA_ELEMENT_VERTICES));
</div>
<div class="parity1 source"><a href="#l972" id="l972">   972</a>         {
</div>
<div class="parity0 source"><a href="#l973" id="l973">   973</a>             pverts-&gt;setId(&quot;vertices&quot;);
</div>
<div class="parity1 source"><a href="#l974" id="l974">   974</a>             domInput_localRef pvertinput = daeSafeCast&lt;domInput_local&gt;(pverts-&gt;add(COLLADA_ELEMENT_INPUT));
</div>
<div class="parity0 source"><a href="#l975" id="l975">   975</a>             pvertinput-&gt;setSemantic(&quot;POSITION&quot;);
</div>
<div class="parity1 source"><a href="#l976" id="l976">   976</a>             pvertinput-&gt;setSource(domUrifragment(*pvertsource, string(&quot;#&quot;)+string(pvertsource-&gt;getID())));
</div>
<div class="parity0 source"><a href="#l977" id="l977">   977</a>         }
</div>
<div class="parity1 source"><a href="#l978" id="l978">   978</a>         _buildAiMesh(scene,scene-&gt;mRootNode,pdommesh,parray, pdomgeom-&gt;getID(),scale);
</div>
<div class="parity0 source"><a href="#l979" id="l979">   979</a>         pacc-&gt;setCount(parray-&gt;getCount());
</div>
<div class="parity1 source"><a href="#l980" id="l980">   980</a>     }
</div>
<div class="parity0 source"><a href="#l981" id="l981">   981</a> 
</div>
<div class="parity1 source"><a href="#l982" id="l982">   982</a>     void _buildAiMesh(const aiScene* scene, aiNode* node, domMeshRef pdommesh, domFloat_arrayRef parray, const string&amp; geomid, const urdf::Vector3&amp; scale)
</div>
<div class="parity0 source"><a href="#l983" id="l983">   983</a>     {
</div>
<div class="parity1 source"><a href="#l984" id="l984">   984</a>         if( !node ) {
</div>
<div class="parity0 source"><a href="#l985" id="l985">   985</a>             return;
</div>
<div class="parity1 source"><a href="#l986" id="l986">   986</a>         }
</div>
<div class="parity0 source"><a href="#l987" id="l987">   987</a>         aiMatrix4x4 transform = node-&gt;mTransformation;
</div>
<div class="parity1 source"><a href="#l988" id="l988">   988</a>         aiNode *pnode = node-&gt;mParent;
</div>
<div class="parity0 source"><a href="#l989" id="l989">   989</a>         while (pnode) {
</div>
<div class="parity1 source"><a href="#l990" id="l990">   990</a>             // Don't convert to y-up orientation, which is what the root node in
</div>
<div class="parity0 source"><a href="#l991" id="l991">   991</a>             // Assimp does
</div>
<div class="parity1 source"><a href="#l992" id="l992">   992</a>             if (pnode-&gt;mParent != NULL) {
</div>
<div class="parity0 source"><a href="#l993" id="l993">   993</a>                 transform = pnode-&gt;mTransformation * transform;
</div>
<div class="parity1 source"><a href="#l994" id="l994">   994</a>             }
</div>
<div class="parity0 source"><a href="#l995" id="l995">   995</a>             pnode = pnode-&gt;mParent;
</div>
<div class="parity1 source"><a href="#l996" id="l996">   996</a>         }
</div>
<div class="parity0 source"><a href="#l997" id="l997">   997</a> 
</div>
<div class="parity1 source"><a href="#l998" id="l998">   998</a>         {
</div>
<div class="parity0 source"><a href="#l999" id="l999">   999</a>             uint32_t vertexOffset = parray-&gt;getCount();
</div>
<div class="parity1 source"><a href="#l1000" id="l1000">  1000</a>             uint32_t nTotalVertices=0;
</div>
<div class="parity0 source"><a href="#l1001" id="l1001">  1001</a>             for (uint32_t i = 0; i &lt; node-&gt;mNumMeshes; i++) {
</div>
<div class="parity1 source"><a href="#l1002" id="l1002">  1002</a>                 aiMesh* input_mesh = scene-&gt;mMeshes[node-&gt;mMeshes[i]];
</div>
<div class="parity0 source"><a href="#l1003" id="l1003">  1003</a>                 nTotalVertices += input_mesh-&gt;mNumVertices;
</div>
<div class="parity1 source"><a href="#l1004" id="l1004">  1004</a>             }
</div>
<div class="parity0 source"><a href="#l1005" id="l1005">  1005</a> 
</div>
<div class="parity1 source"><a href="#l1006" id="l1006">  1006</a>             parray-&gt;getValue().grow(parray-&gt;getCount()+nTotalVertices*3);
</div>
<div class="parity0 source"><a href="#l1007" id="l1007">  1007</a>             parray-&gt;setCount(parray-&gt;getCount()+nTotalVertices);
</div>
<div class="parity1 source"><a href="#l1008" id="l1008">  1008</a> 
</div>
<div class="parity0 source"><a href="#l1009" id="l1009">  1009</a>             for (uint32_t i = 0; i &lt; node-&gt;mNumMeshes; i++) {
</div>
<div class="parity1 source"><a href="#l1010" id="l1010">  1010</a>                 aiMesh* input_mesh = scene-&gt;mMeshes[node-&gt;mMeshes[i]];
</div>
<div class="parity0 source"><a href="#l1011" id="l1011">  1011</a>                 for (uint32_t j = 0; j &lt; input_mesh-&gt;mNumVertices; j++) {
</div>
<div class="parity1 source"><a href="#l1012" id="l1012">  1012</a>                     aiVector3D p = input_mesh-&gt;mVertices[j];
</div>
<div class="parity0 source"><a href="#l1013" id="l1013">  1013</a>                     p *= transform;
</div>
<div class="parity1 source"><a href="#l1014" id="l1014">  1014</a>                     parray-&gt;getValue().append(p.x*scale.x);
</div>
<div class="parity0 source"><a href="#l1015" id="l1015">  1015</a>                     parray-&gt;getValue().append(p.y*scale.y);
</div>
<div class="parity1 source"><a href="#l1016" id="l1016">  1016</a>                     parray-&gt;getValue().append(p.z*scale.z);
</div>
<div class="parity0 source"><a href="#l1017" id="l1017">  1017</a>                 }
</div>
<div class="parity1 source"><a href="#l1018" id="l1018">  1018</a>             }
</div>
<div class="parity0 source"><a href="#l1019" id="l1019">  1019</a> 
</div>
<div class="parity1 source"><a href="#l1020" id="l1020">  1020</a>             // in order to save space, separate triangles from poly lists
</div>
<div class="parity0 source"><a href="#l1021" id="l1021">  1021</a>             
</div>
<div class="parity1 source"><a href="#l1022" id="l1022">  1022</a>             vector&lt;int&gt; triangleindices, otherindices;
</div>
<div class="parity0 source"><a href="#l1023" id="l1023">  1023</a>             int nNumOtherPrimitives = 0;
</div>
<div class="parity1 source"><a href="#l1024" id="l1024">  1024</a>             for (uint32_t i = 0; i &lt; node-&gt;mNumMeshes; i++) {
</div>
<div class="parity0 source"><a href="#l1025" id="l1025">  1025</a>                 aiMesh* input_mesh = scene-&gt;mMeshes[node-&gt;mMeshes[i]];
</div>
<div class="parity1 source"><a href="#l1026" id="l1026">  1026</a>                 uint32_t indexCount = 0, otherIndexCount = 0;
</div>
<div class="parity0 source"><a href="#l1027" id="l1027">  1027</a>                 for (uint32_t j = 0; j &lt; input_mesh-&gt;mNumFaces; j++) {
</div>
<div class="parity1 source"><a href="#l1028" id="l1028">  1028</a>                     aiFace&amp; face = input_mesh-&gt;mFaces[j];
</div>
<div class="parity0 source"><a href="#l1029" id="l1029">  1029</a>                     if( face.mNumIndices == 3 ) {
</div>
<div class="parity1 source"><a href="#l1030" id="l1030">  1030</a>                         indexCount += face.mNumIndices;
</div>
<div class="parity0 source"><a href="#l1031" id="l1031">  1031</a>                     }
</div>
<div class="parity1 source"><a href="#l1032" id="l1032">  1032</a>                     else {
</div>
<div class="parity0 source"><a href="#l1033" id="l1033">  1033</a>                         otherIndexCount += face.mNumIndices;
</div>
<div class="parity1 source"><a href="#l1034" id="l1034">  1034</a>                     }
</div>
<div class="parity0 source"><a href="#l1035" id="l1035">  1035</a>                 }
</div>
<div class="parity1 source"><a href="#l1036" id="l1036">  1036</a>                 triangleindices.reserve(triangleindices.size()+indexCount);
</div>
<div class="parity0 source"><a href="#l1037" id="l1037">  1037</a>                 otherindices.reserve(otherindices.size()+otherIndexCount);
</div>
<div class="parity1 source"><a href="#l1038" id="l1038">  1038</a>                 for (uint32_t j = 0; j &lt; input_mesh-&gt;mNumFaces; j++) {
</div>
<div class="parity0 source"><a href="#l1039" id="l1039">  1039</a>                     aiFace&amp; face = input_mesh-&gt;mFaces[j];
</div>
<div class="parity1 source"><a href="#l1040" id="l1040">  1040</a>                     if( face.mNumIndices == 3 ) {
</div>
<div class="parity0 source"><a href="#l1041" id="l1041">  1041</a>                         triangleindices.push_back(vertexOffset+face.mIndices[0]);
</div>
<div class="parity1 source"><a href="#l1042" id="l1042">  1042</a>                         triangleindices.push_back(vertexOffset+face.mIndices[1]);
</div>
<div class="parity0 source"><a href="#l1043" id="l1043">  1043</a>                         triangleindices.push_back(vertexOffset+face.mIndices[2]);
</div>
<div class="parity1 source"><a href="#l1044" id="l1044">  1044</a>                     }
</div>
<div class="parity0 source"><a href="#l1045" id="l1045">  1045</a>                     else {
</div>
<div class="parity1 source"><a href="#l1046" id="l1046">  1046</a>                         for (uint32_t k = 0; k &lt; face.mNumIndices; ++k) {
</div>
<div class="parity0 source"><a href="#l1047" id="l1047">  1047</a>                             otherindices.push_back(face.mIndices[k]+vertexOffset);
</div>
<div class="parity1 source"><a href="#l1048" id="l1048">  1048</a>                         }
</div>
<div class="parity0 source"><a href="#l1049" id="l1049">  1049</a>                         nNumOtherPrimitives++;
</div>
<div class="parity1 source"><a href="#l1050" id="l1050">  1050</a>                     }
</div>
<div class="parity0 source"><a href="#l1051" id="l1051">  1051</a>                 }
</div>
<div class="parity1 source"><a href="#l1052" id="l1052">  1052</a>                 vertexOffset += input_mesh-&gt;mNumVertices;
</div>
<div class="parity0 source"><a href="#l1053" id="l1053">  1053</a>             }
</div>
<div class="parity1 source"><a href="#l1054" id="l1054">  1054</a> 
</div>
<div class="parity0 source"><a href="#l1055" id="l1055">  1055</a>             if( triangleindices.size() &gt; 0 ) {
</div>
<div class="parity1 source"><a href="#l1056" id="l1056">  1056</a>                 domTrianglesRef ptris = daeSafeCast&lt;domTriangles&gt;(pdommesh-&gt;add(COLLADA_ELEMENT_TRIANGLES));
</div>
<div class="parity0 source"><a href="#l1057" id="l1057">  1057</a>                 ptris-&gt;setCount(triangleindices.size()/3);
</div>
<div class="parity1 source"><a href="#l1058" id="l1058">  1058</a>                 ptris-&gt;setMaterial(&quot;mat0&quot;);
</div>
<div class="parity0 source"><a href="#l1059" id="l1059">  1059</a>                 domInput_local_offsetRef pvertoffset = daeSafeCast&lt;domInput_local_offset&gt;(ptris-&gt;add(COLLADA_ELEMENT_INPUT));
</div>
<div class="parity1 source"><a href="#l1060" id="l1060">  1060</a>                 pvertoffset-&gt;setSemantic(&quot;VERTEX&quot;);
</div>
<div class="parity0 source"><a href="#l1061" id="l1061">  1061</a>                 pvertoffset-&gt;setOffset(0);
</div>
<div class="parity1 source"><a href="#l1062" id="l1062">  1062</a>                 pvertoffset-&gt;setSource(domUrifragment(*pdommesh-&gt;getVertices(), str(boost::format(&quot;#%s/vertices&quot;)%geomid)));
</div>
<div class="parity0 source"><a href="#l1063" id="l1063">  1063</a>                 domPRef pindices = daeSafeCast&lt;domP&gt;(ptris-&gt;add(COLLADA_ELEMENT_P));
</div>
<div class="parity1 source"><a href="#l1064" id="l1064">  1064</a>                 pindices-&gt;getValue().setCount(triangleindices.size());
</div>
<div class="parity0 source"><a href="#l1065" id="l1065">  1065</a>                 for(size_t ind = 0; ind &lt; triangleindices.size(); ++ind) {
</div>
<div class="parity1 source"><a href="#l1066" id="l1066">  1066</a>                     pindices-&gt;getValue()[ind] = triangleindices[ind];
</div>
<div class="parity0 source"><a href="#l1067" id="l1067">  1067</a>                 }
</div>
<div class="parity1 source"><a href="#l1068" id="l1068">  1068</a>             }
</div>
<div class="parity0 source"><a href="#l1069" id="l1069">  1069</a> 
</div>
<div class="parity1 source"><a href="#l1070" id="l1070">  1070</a>             if( nNumOtherPrimitives &gt; 0 ) {
</div>
<div class="parity0 source"><a href="#l1071" id="l1071">  1071</a>                 domPolylistRef ptris = daeSafeCast&lt;domPolylist&gt;(pdommesh-&gt;add(COLLADA_ELEMENT_POLYLIST));
</div>
<div class="parity1 source"><a href="#l1072" id="l1072">  1072</a>                 ptris-&gt;setCount(nNumOtherPrimitives);
</div>
<div class="parity0 source"><a href="#l1073" id="l1073">  1073</a>                 ptris-&gt;setMaterial(&quot;mat0&quot;);
</div>
<div class="parity1 source"><a href="#l1074" id="l1074">  1074</a>                 domInput_local_offsetRef pvertoffset = daeSafeCast&lt;domInput_local_offset&gt;(ptris-&gt;add(COLLADA_ELEMENT_INPUT));
</div>
<div class="parity0 source"><a href="#l1075" id="l1075">  1075</a>                 pvertoffset-&gt;setSemantic(&quot;VERTEX&quot;);
</div>
<div class="parity1 source"><a href="#l1076" id="l1076">  1076</a>                 pvertoffset-&gt;setSource(domUrifragment(*pdommesh-&gt;getVertices(), str(boost::format(&quot;#%s/vertices&quot;)%geomid)));
</div>
<div class="parity0 source"><a href="#l1077" id="l1077">  1077</a>                 domPRef pindices = daeSafeCast&lt;domP&gt;(ptris-&gt;add(COLLADA_ELEMENT_P));
</div>
<div class="parity1 source"><a href="#l1078" id="l1078">  1078</a>                 pindices-&gt;getValue().setCount(otherindices.size());
</div>
<div class="parity0 source"><a href="#l1079" id="l1079">  1079</a>                 for(size_t ind = 0; ind &lt; otherindices.size(); ++ind) {
</div>
<div class="parity1 source"><a href="#l1080" id="l1080">  1080</a>                     pindices-&gt;getValue()[ind] = otherindices[ind];
</div>
<div class="parity0 source"><a href="#l1081" id="l1081">  1081</a>                 }
</div>
<div class="parity1 source"><a href="#l1082" id="l1082">  1082</a>                 
</div>
<div class="parity0 source"><a href="#l1083" id="l1083">  1083</a>                 domPolylist::domVcountRef pcount = daeSafeCast&lt;domPolylist::domVcount&gt;(ptris-&gt;add(COLLADA_ELEMENT_VCOUNT));
</div>
<div class="parity1 source"><a href="#l1084" id="l1084">  1084</a>                 pcount-&gt;getValue().setCount(nNumOtherPrimitives);
</div>
<div class="parity0 source"><a href="#l1085" id="l1085">  1085</a>                 uint32_t offset = 0;
</div>
<div class="parity1 source"><a href="#l1086" id="l1086">  1086</a>                 for (uint32_t i = 0; i &lt; node-&gt;mNumMeshes; i++) {
</div>
<div class="parity0 source"><a href="#l1087" id="l1087">  1087</a>                     aiMesh* input_mesh = scene-&gt;mMeshes[node-&gt;mMeshes[i]];
</div>
<div class="parity1 source"><a href="#l1088" id="l1088">  1088</a>                     for (uint32_t j = 0; j &lt; input_mesh-&gt;mNumFaces; j++) {
</div>
<div class="parity0 source"><a href="#l1089" id="l1089">  1089</a>                         aiFace&amp; face = input_mesh-&gt;mFaces[j];
</div>
<div class="parity1 source"><a href="#l1090" id="l1090">  1090</a>                         if( face.mNumIndices &gt; 3 ) {
</div>
<div class="parity0 source"><a href="#l1091" id="l1091">  1091</a>                             pcount-&gt;getValue()[offset++] = face.mNumIndices;
</div>
<div class="parity1 source"><a href="#l1092" id="l1092">  1092</a>                         }
</div>
<div class="parity0 source"><a href="#l1093" id="l1093">  1093</a>                     }
</div>
<div class="parity1 source"><a href="#l1094" id="l1094">  1094</a>                 }
</div>
<div class="parity0 source"><a href="#l1095" id="l1095">  1095</a>             }
</div>
<div class="parity1 source"><a href="#l1096" id="l1096">  1096</a>         }
</div>
<div class="parity0 source"><a href="#l1097" id="l1097">  1097</a> 
</div>
<div class="parity1 source"><a href="#l1098" id="l1098">  1098</a>         for (uint32_t i=0; i &lt; node-&gt;mNumChildren; ++i) {
</div>
<div class="parity0 source"><a href="#l1099" id="l1099">  1099</a>             _buildAiMesh(scene, node-&gt;mChildren[i], pdommesh,parray,geomid,scale);
</div>
<div class="parity1 source"><a href="#l1100" id="l1100">  1100</a>         }
</div>
<div class="parity0 source"><a href="#l1101" id="l1101">  1101</a>     }
</div>
<div class="parity1 source"><a href="#l1102" id="l1102">  1102</a> 
</div>
<div class="parity0 source"><a href="#l1103" id="l1103">  1103</a> 
</div>
<div class="parity1 source"><a href="#l1104" id="l1104">  1104</a>     domEffectRef _WriteEffect(std::string const&amp; effect_id, urdf::Color const&amp; color_ambient, urdf::Color const&amp; color_diffuse)
</div>
<div class="parity0 source"><a href="#l1105" id="l1105">  1105</a>     {
</div>
<div class="parity1 source"><a href="#l1106" id="l1106">  1106</a>         // &lt;effect id=&quot;g1.link0.geom0.eff&quot;&gt;
</div>
<div class="parity0 source"><a href="#l1107" id="l1107">  1107</a>         domEffectRef effect = daeSafeCast&lt;domEffect&gt;(_effectsLib-&gt;add(COLLADA_ELEMENT_EFFECT));
</div>
<div class="parity1 source"><a href="#l1108" id="l1108">  1108</a>         effect-&gt;setId(effect_id.c_str());
</div>
<div class="parity0 source"><a href="#l1109" id="l1109">  1109</a>         {
</div>
<div class="parity1 source"><a href="#l1110" id="l1110">  1110</a>             // &lt;profile_COMMON&gt;
</div>
<div class="parity0 source"><a href="#l1111" id="l1111">  1111</a>             domProfile_commonRef profile = daeSafeCast&lt;domProfile_common&gt;(effect-&gt;add(COLLADA_ELEMENT_PROFILE_COMMON));
</div>
<div class="parity1 source"><a href="#l1112" id="l1112">  1112</a>             {
</div>
<div class="parity0 source"><a href="#l1113" id="l1113">  1113</a>                 // &lt;technique sid=&quot;&quot;&gt;
</div>
<div class="parity1 source"><a href="#l1114" id="l1114">  1114</a>                 domProfile_common::domTechniqueRef technique = daeSafeCast&lt;domProfile_common::domTechnique&gt;(profile-&gt;add(COLLADA_ELEMENT_TECHNIQUE));
</div>
<div class="parity0 source"><a href="#l1115" id="l1115">  1115</a>                 {
</div>
<div class="parity1 source"><a href="#l1116" id="l1116">  1116</a>                     // &lt;phong&gt;
</div>
<div class="parity0 source"><a href="#l1117" id="l1117">  1117</a>                     domProfile_common::domTechnique::domPhongRef phong = daeSafeCast&lt;domProfile_common::domTechnique::domPhong&gt;(technique-&gt;add(COLLADA_ELEMENT_PHONG));
</div>
<div class="parity1 source"><a href="#l1118" id="l1118">  1118</a>                     {
</div>
<div class="parity0 source"><a href="#l1119" id="l1119">  1119</a>                         // &lt;ambient&gt;
</div>
<div class="parity1 source"><a href="#l1120" id="l1120">  1120</a>                         domFx_common_color_or_textureRef ambient = daeSafeCast&lt;domFx_common_color_or_texture&gt;(phong-&gt;add(COLLADA_ELEMENT_AMBIENT));
</div>
<div class="parity0 source"><a href="#l1121" id="l1121">  1121</a>                         {
</div>
<div class="parity1 source"><a href="#l1122" id="l1122">  1122</a>                             // &lt;color&gt;r g b a
</div>
<div class="parity0 source"><a href="#l1123" id="l1123">  1123</a>                             domFx_common_color_or_texture::domColorRef ambient_color = daeSafeCast&lt;domFx_common_color_or_texture::domColor&gt;(ambient-&gt;add(COLLADA_ELEMENT_COLOR));
</div>
<div class="parity1 source"><a href="#l1124" id="l1124">  1124</a>                             ambient_color-&gt;getValue().setCount(4);
</div>
<div class="parity0 source"><a href="#l1125" id="l1125">  1125</a>                             ambient_color-&gt;getValue()[0] = color_ambient.r;
</div>
<div class="parity1 source"><a href="#l1126" id="l1126">  1126</a>                             ambient_color-&gt;getValue()[1] = color_ambient.g;
</div>
<div class="parity0 source"><a href="#l1127" id="l1127">  1127</a>                             ambient_color-&gt;getValue()[2] = color_ambient.b;
</div>
<div class="parity1 source"><a href="#l1128" id="l1128">  1128</a>                             ambient_color-&gt;getValue()[3] = color_ambient.a;
</div>
<div class="parity0 source"><a href="#l1129" id="l1129">  1129</a>                             // &lt;/color&gt;
</div>
<div class="parity1 source"><a href="#l1130" id="l1130">  1130</a>                         }
</div>
<div class="parity0 source"><a href="#l1131" id="l1131">  1131</a>                         // &lt;/ambient&gt;
</div>
<div class="parity1 source"><a href="#l1132" id="l1132">  1132</a> 
</div>
<div class="parity0 source"><a href="#l1133" id="l1133">  1133</a>                         // &lt;diffuse&gt;
</div>
<div class="parity1 source"><a href="#l1134" id="l1134">  1134</a>                         domFx_common_color_or_textureRef diffuse = daeSafeCast&lt;domFx_common_color_or_texture&gt;(phong-&gt;add(COLLADA_ELEMENT_DIFFUSE));
</div>
<div class="parity0 source"><a href="#l1135" id="l1135">  1135</a>                         {
</div>
<div class="parity1 source"><a href="#l1136" id="l1136">  1136</a>                             // &lt;color&gt;r g b a
</div>
<div class="parity0 source"><a href="#l1137" id="l1137">  1137</a>                             domFx_common_color_or_texture::domColorRef diffuse_color = daeSafeCast&lt;domFx_common_color_or_texture::domColor&gt;(diffuse-&gt;add(COLLADA_ELEMENT_COLOR));
</div>
<div class="parity1 source"><a href="#l1138" id="l1138">  1138</a>                             diffuse_color-&gt;getValue().setCount(4);
</div>
<div class="parity0 source"><a href="#l1139" id="l1139">  1139</a>                             diffuse_color-&gt;getValue()[0] = color_diffuse.r;
</div>
<div class="parity1 source"><a href="#l1140" id="l1140">  1140</a>                             diffuse_color-&gt;getValue()[1] = color_diffuse.g;
</div>
<div class="parity0 source"><a href="#l1141" id="l1141">  1141</a>                             diffuse_color-&gt;getValue()[2] = color_diffuse.b;
</div>
<div class="parity1 source"><a href="#l1142" id="l1142">  1142</a>                             diffuse_color-&gt;getValue()[3] = color_diffuse.a;
</div>
<div class="parity0 source"><a href="#l1143" id="l1143">  1143</a>                             // &lt;/color&gt;
</div>
<div class="parity1 source"><a href="#l1144" id="l1144">  1144</a>                         }
</div>
<div class="parity0 source"><a href="#l1145" id="l1145">  1145</a>                         // &lt;/diffuse&gt;
</div>
<div class="parity1 source"><a href="#l1146" id="l1146">  1146</a>                     }
</div>
<div class="parity0 source"><a href="#l1147" id="l1147">  1147</a>                     // &lt;/phong&gt;
</div>
<div class="parity1 source"><a href="#l1148" id="l1148">  1148</a>                 }
</div>
<div class="parity0 source"><a href="#l1149" id="l1149">  1149</a>                 // &lt;/technique&gt;
</div>
<div class="parity1 source"><a href="#l1150" id="l1150">  1150</a>             }
</div>
<div class="parity0 source"><a href="#l1151" id="l1151">  1151</a>             // &lt;/profile_COMMON&gt;
</div>
<div class="parity1 source"><a href="#l1152" id="l1152">  1152</a>         }
</div>
<div class="parity0 source"><a href="#l1153" id="l1153">  1153</a>         // &lt;/effect&gt;
</div>
<div class="parity1 source"><a href="#l1154" id="l1154">  1154</a> 
</div>
<div class="parity0 source"><a href="#l1155" id="l1155">  1155</a>         return effect;
</div>
<div class="parity1 source"><a href="#l1156" id="l1156">  1156</a>     }
</div>
<div class="parity0 source"><a href="#l1157" id="l1157">  1157</a> 
</div>
<div class="parity1 source"><a href="#l1158" id="l1158">  1158</a>     /// \brief Write transformation
</div>
<div class="parity0 source"><a href="#l1159" id="l1159">  1159</a>     /// \param pelt Element to transform
</div>
<div class="parity1 source"><a href="#l1160" id="l1160">  1160</a>     /// \param t Transform to write
</div>
<div class="parity0 source"><a href="#l1161" id="l1161">  1161</a>     void _WriteTransformation(daeElementRef pelt, const urdf::Pose&amp; t)
</div>
<div class="parity1 source"><a href="#l1162" id="l1162">  1162</a>     {
</div>
<div class="parity0 source"><a href="#l1163" id="l1163">  1163</a>         domRotateRef prot = daeSafeCast&lt;domRotate&gt;(pelt-&gt;add(COLLADA_ELEMENT_ROTATE,0));
</div>
<div class="parity1 source"><a href="#l1164" id="l1164">  1164</a>         domTranslateRef ptrans = daeSafeCast&lt;domTranslate&gt;(pelt-&gt;add(COLLADA_ELEMENT_TRANSLATE,0));
</div>
<div class="parity0 source"><a href="#l1165" id="l1165">  1165</a>         ptrans-&gt;getValue().setCount(3);
</div>
<div class="parity1 source"><a href="#l1166" id="l1166">  1166</a>         ptrans-&gt;getValue()[0] = t.position.x;
</div>
<div class="parity0 source"><a href="#l1167" id="l1167">  1167</a>         ptrans-&gt;getValue()[1] = t.position.y;
</div>
<div class="parity1 source"><a href="#l1168" id="l1168">  1168</a>         ptrans-&gt;getValue()[2] = t.position.z;
</div>
<div class="parity0 source"><a href="#l1169" id="l1169">  1169</a> 
</div>
<div class="parity1 source"><a href="#l1170" id="l1170">  1170</a>         prot-&gt;getValue().setCount(4);
</div>
<div class="parity0 source"><a href="#l1171" id="l1171">  1171</a>         // extract axis from quaternion
</div>
<div class="parity1 source"><a href="#l1172" id="l1172">  1172</a>         double sinang = t.rotation.x*t.rotation.x+t.rotation.y*t.rotation.y+t.rotation.z*t.rotation.z;
</div>
<div class="parity0 source"><a href="#l1173" id="l1173">  1173</a>         if( std::fabs(sinang) &lt; 1e-10 ) {
</div>
<div class="parity1 source"><a href="#l1174" id="l1174">  1174</a>             prot-&gt;getValue()[0] = 1;
</div>
<div class="parity0 source"><a href="#l1175" id="l1175">  1175</a>             prot-&gt;getValue()[1] = 0;
</div>
<div class="parity1 source"><a href="#l1176" id="l1176">  1176</a>             prot-&gt;getValue()[2] = 0;
</div>
<div class="parity0 source"><a href="#l1177" id="l1177">  1177</a>             prot-&gt;getValue()[3] = 0;
</div>
<div class="parity1 source"><a href="#l1178" id="l1178">  1178</a>         }
</div>
<div class="parity0 source"><a href="#l1179" id="l1179">  1179</a>         else {
</div>
<div class="parity1 source"><a href="#l1180" id="l1180">  1180</a>             urdf::Rotation quat;
</div>
<div class="parity0 source"><a href="#l1181" id="l1181">  1181</a>             if( t.rotation.w &lt; 0 ) {
</div>
<div class="parity1 source"><a href="#l1182" id="l1182">  1182</a>                 quat.x = -t.rotation.x;
</div>
<div class="parity0 source"><a href="#l1183" id="l1183">  1183</a>                 quat.y = -t.rotation.y;
</div>
<div class="parity1 source"><a href="#l1184" id="l1184">  1184</a>                 quat.z = -t.rotation.z;
</div>
<div class="parity0 source"><a href="#l1185" id="l1185">  1185</a>                 quat.w = -t.rotation.w;
</div>
<div class="parity1 source"><a href="#l1186" id="l1186">  1186</a>             }
</div>
<div class="parity0 source"><a href="#l1187" id="l1187">  1187</a>             else {
</div>
<div class="parity1 source"><a href="#l1188" id="l1188">  1188</a>                 quat = t.rotation;
</div>
<div class="parity0 source"><a href="#l1189" id="l1189">  1189</a>             }
</div>
<div class="parity1 source"><a href="#l1190" id="l1190">  1190</a>             sinang = std::sqrt(sinang);
</div>
<div class="parity0 source"><a href="#l1191" id="l1191">  1191</a>             prot-&gt;getValue()[0] = quat.x/sinang;
</div>
<div class="parity1 source"><a href="#l1192" id="l1192">  1192</a>             prot-&gt;getValue()[1] = quat.y/sinang;
</div>
<div class="parity0 source"><a href="#l1193" id="l1193">  1193</a>             prot-&gt;getValue()[2] = quat.z/sinang;
</div>
<div class="parity1 source"><a href="#l1194" id="l1194">  1194</a>             prot-&gt;getValue()[3] = angles::to_degrees(2.0*std::atan2(sinang,quat.w));
</div>
<div class="parity0 source"><a href="#l1195" id="l1195">  1195</a>         }
</div>
<div class="parity1 source"><a href="#l1196" id="l1196">  1196</a>     }
</div>
<div class="parity0 source"><a href="#l1197" id="l1197">  1197</a> 
</div>
<div class="parity1 source"><a href="#l1198" id="l1198">  1198</a>     // binding in instance_kinematics_scene
</div>
<div class="parity0 source"><a href="#l1199" id="l1199">  1199</a>     void _WriteBindingsInstance_kinematics_scene()
</div>
<div class="parity1 source"><a href="#l1200" id="l1200">  1200</a>     {
</div>
<div class="parity0 source"><a href="#l1201" id="l1201">  1201</a>         FOREACHC(it, _iasout-&gt;vkinematicsbindings) {
</div>
<div class="parity1 source"><a href="#l1202" id="l1202">  1202</a>             domBind_kinematics_modelRef pmodelbind = daeSafeCast&lt;domBind_kinematics_model&gt;(_scene.kiscene-&gt;add(COLLADA_ELEMENT_BIND_KINEMATICS_MODEL));
</div>
<div class="parity0 source"><a href="#l1203" id="l1203">  1203</a>             pmodelbind-&gt;setNode(it-&gt;second.c_str());
</div>
<div class="parity1 source"><a href="#l1204" id="l1204">  1204</a>             daeSafeCast&lt;domCommon_param&gt;(pmodelbind-&gt;add(COLLADA_ELEMENT_PARAM))-&gt;setValue(it-&gt;first.c_str());
</div>
<div class="parity0 source"><a href="#l1205" id="l1205">  1205</a>         }
</div>
<div class="parity1 source"><a href="#l1206" id="l1206">  1206</a>         FOREACHC(it, _iasout-&gt;vaxissids) {
</div>
<div class="parity0 source"><a href="#l1207" id="l1207">  1207</a>             domBind_joint_axisRef pjointbind = daeSafeCast&lt;domBind_joint_axis&gt;(_scene.kiscene-&gt;add(COLLADA_ELEMENT_BIND_JOINT_AXIS));
</div>
<div class="parity1 source"><a href="#l1208" id="l1208">  1208</a>             pjointbind-&gt;setTarget(it-&gt;jointnodesid.c_str());
</div>
<div class="parity0 source"><a href="#l1209" id="l1209">  1209</a>             daeSafeCast&lt;domCommon_param&gt;(pjointbind-&gt;add(COLLADA_ELEMENT_AXIS)-&gt;add(COLLADA_TYPE_PARAM))-&gt;setValue(it-&gt;axissid.c_str());
</div>
<div class="parity1 source"><a href="#l1210" id="l1210">  1210</a>             daeSafeCast&lt;domCommon_param&gt;(pjointbind-&gt;add(COLLADA_ELEMENT_VALUE)-&gt;add(COLLADA_TYPE_PARAM))-&gt;setValue(it-&gt;valuesid.c_str());
</div>
<div class="parity0 source"><a href="#l1211" id="l1211">  1211</a>         }
</div>
<div class="parity1 source"><a href="#l1212" id="l1212">  1212</a>     }
</div>
<div class="parity0 source"><a href="#l1213" id="l1213">  1213</a> 
</div>
<div class="parity1 source"><a href="#l1214" id="l1214">  1214</a> private:
</div>
<div class="parity0 source"><a href="#l1215" id="l1215">  1215</a>     static urdf::Vector3 _poseMult(const urdf::Pose&amp; p, const urdf::Vector3&amp; v)
</div>
<div class="parity1 source"><a href="#l1216" id="l1216">  1216</a>     {
</div>
<div class="parity0 source"><a href="#l1217" id="l1217">  1217</a>         double ww = 2 * p.rotation.x * p.rotation.x;
</div>
<div class="parity1 source"><a href="#l1218" id="l1218">  1218</a>         double wx = 2 * p.rotation.x * p.rotation.y;
</div>
<div class="parity0 source"><a href="#l1219" id="l1219">  1219</a>         double wy = 2 * p.rotation.x * p.rotation.z;
</div>
<div class="parity1 source"><a href="#l1220" id="l1220">  1220</a>         double wz = 2 * p.rotation.x * p.rotation.w;
</div>
<div class="parity0 source"><a href="#l1221" id="l1221">  1221</a>         double xx = 2 * p.rotation.y * p.rotation.y;
</div>
<div class="parity1 source"><a href="#l1222" id="l1222">  1222</a>         double xy = 2 * p.rotation.y * p.rotation.z;
</div>
<div class="parity0 source"><a href="#l1223" id="l1223">  1223</a>         double xz = 2 * p.rotation.y * p.rotation.w;
</div>
<div class="parity1 source"><a href="#l1224" id="l1224">  1224</a>         double yy = 2 * p.rotation.z * p.rotation.z;
</div>
<div class="parity0 source"><a href="#l1225" id="l1225">  1225</a>         double yz = 2 * p.rotation.z * p.rotation.w;
</div>
<div class="parity1 source"><a href="#l1226" id="l1226">  1226</a>         urdf::Vector3 vnew;
</div>
<div class="parity0 source"><a href="#l1227" id="l1227">  1227</a>         vnew.x = (1-xx-yy) * v.x + (wx-yz) * v.y + (wy+xz)*v.z + p.position.x;
</div>
<div class="parity1 source"><a href="#l1228" id="l1228">  1228</a>         vnew.y = (wx+yz) * v.x + (1-ww-yy) * v.y + (xy-wz)*v.z + p.position.y;
</div>
<div class="parity0 source"><a href="#l1229" id="l1229">  1229</a>         vnew.z = (wy-xz) * v.x + (xy+wz) * v.y + (1-ww-xx)*v.z + p.position.z;
</div>
<div class="parity1 source"><a href="#l1230" id="l1230">  1230</a>         return vnew;
</div>
<div class="parity0 source"><a href="#l1231" id="l1231">  1231</a>     }
</div>
<div class="parity1 source"><a href="#l1232" id="l1232">  1232</a> 
</div>
<div class="parity0 source"><a href="#l1233" id="l1233">  1233</a>     static urdf::Pose _poseInverse(const urdf::Pose&amp; p)
</div>
<div class="parity1 source"><a href="#l1234" id="l1234">  1234</a>     {
</div>
<div class="parity0 source"><a href="#l1235" id="l1235">  1235</a>         urdf::Pose pinv;
</div>
<div class="parity1 source"><a href="#l1236" id="l1236">  1236</a>         pinv.rotation.x = -p.rotation.x;
</div>
<div class="parity0 source"><a href="#l1237" id="l1237">  1237</a>         pinv.rotation.y = -p.rotation.y;
</div>
<div class="parity1 source"><a href="#l1238" id="l1238">  1238</a>         pinv.rotation.z = -p.rotation.z;
</div>
<div class="parity0 source"><a href="#l1239" id="l1239">  1239</a>         pinv.rotation.w = p.rotation.w;
</div>
<div class="parity1 source"><a href="#l1240" id="l1240">  1240</a>         urdf::Vector3 t = _poseMult(pinv,p.position);
</div>
<div class="parity0 source"><a href="#l1241" id="l1241">  1241</a>         pinv.position.x = -t.x;
</div>
<div class="parity1 source"><a href="#l1242" id="l1242">  1242</a>         pinv.position.y = -t.y;
</div>
<div class="parity0 source"><a href="#l1243" id="l1243">  1243</a>         pinv.position.z = -t.z;
</div>
<div class="parity1 source"><a href="#l1244" id="l1244">  1244</a>         return pinv;
</div>
<div class="parity0 source"><a href="#l1245" id="l1245">  1245</a>     }
</div>
<div class="parity1 source"><a href="#l1246" id="l1246">  1246</a> 
</div>
<div class="parity0 source"><a href="#l1247" id="l1247">  1247</a>     /// \brief computes a collada-compliant sid from the urdf name
</div>
<div class="parity1 source"><a href="#l1248" id="l1248">  1248</a>     static std::string _ComputeId(const std::string&amp; name)
</div>
<div class="parity0 source"><a href="#l1249" id="l1249">  1249</a>     {
</div>
<div class="parity1 source"><a href="#l1250" id="l1250">  1250</a>         std::string newname = name;
</div>
<div class="parity0 source"><a href="#l1251" id="l1251">  1251</a>         for(size_t i = 0; i &lt; newname.size(); ++i) {
</div>
<div class="parity1 source"><a href="#l1252" id="l1252">  1252</a>             if( newname[i] == '/' || newname[i] == ' ' || newname[i] == '.' ) {
</div>
<div class="parity0 source"><a href="#l1253" id="l1253">  1253</a>                 newname[i] = '_';
</div>
<div class="parity1 source"><a href="#l1254" id="l1254">  1254</a>             }
</div>
<div class="parity0 source"><a href="#l1255" id="l1255">  1255</a>         }
</div>
<div class="parity1 source"><a href="#l1256" id="l1256">  1256</a>         return newname;
</div>
<div class="parity0 source"><a href="#l1257" id="l1257">  1257</a>     }
</div>
<div class="parity1 source"><a href="#l1258" id="l1258">  1258</a> 
</div>
<div class="parity0 source"><a href="#l1259" id="l1259">  1259</a>     int _writeoptions;
</div>
<div class="parity1 source"><a href="#l1260" id="l1260">  1260</a> 
</div>
<div class="parity0 source"><a href="#l1261" id="l1261">  1261</a>     const urdf::Model&amp;              _robot;
</div>
<div class="parity1 source"><a href="#l1262" id="l1262">  1262</a>     boost::shared_ptr&lt;DAE&gt;          _collada;
</div>
<div class="parity0 source"><a href="#l1263" id="l1263">  1263</a>     domCOLLADA*                     _dom;
</div>
<div class="parity1 source"><a href="#l1264" id="l1264">  1264</a>     domCOLLADA::domSceneRef         _globalscene;
</div>
<div class="parity0 source"><a href="#l1265" id="l1265">  1265</a> 
</div>
<div class="parity1 source"><a href="#l1266" id="l1266">  1266</a>     domLibrary_visual_scenesRef _visualScenesLib;
</div>
<div class="parity0 source"><a href="#l1267" id="l1267">  1267</a>     domLibrary_kinematics_scenesRef _kinematicsScenesLib;
</div>
<div class="parity1 source"><a href="#l1268" id="l1268">  1268</a>     domLibrary_kinematics_modelsRef _kinematicsModelsLib;
</div>
<div class="parity0 source"><a href="#l1269" id="l1269">  1269</a>     domLibrary_articulated_systemsRef _articulatedSystemsLib;
</div>
<div class="parity1 source"><a href="#l1270" id="l1270">  1270</a>     domLibrary_physics_scenesRef _physicsScenesLib;
</div>
<div class="parity0 source"><a href="#l1271" id="l1271">  1271</a>     domLibrary_materialsRef _materialsLib;
</div>
<div class="parity1 source"><a href="#l1272" id="l1272">  1272</a>     domLibrary_effectsRef _effectsLib;
</div>
<div class="parity0 source"><a href="#l1273" id="l1273">  1273</a>     domLibrary_geometriesRef _geometriesLib;
</div>
<div class="parity1 source"><a href="#l1274" id="l1274">  1274</a>     domTechniqueRef _sensorsLib;///&lt; custom sensors library
</div>
<div class="parity0 source"><a href="#l1275" id="l1275">  1275</a>     SCENE _scene;
</div>
<div class="parity1 source"><a href="#l1276" id="l1276">  1276</a> 
</div>
<div class="parity0 source"><a href="#l1277" id="l1277">  1277</a>     boost::shared_ptr&lt;instance_kinematics_model_output&gt; _ikmout;
</div>
<div class="parity1 source"><a href="#l1278" id="l1278">  1278</a>     boost::shared_ptr&lt;instance_articulated_system_output&gt; _iasout;
</div>
<div class="parity0 source"><a href="#l1279" id="l1279">  1279</a>     std::map&lt; boost::shared_ptr&lt;const urdf::Joint&gt;, int &gt; _mapjointindices;
</div>
<div class="parity1 source"><a href="#l1280" id="l1280">  1280</a>     std::map&lt; boost::shared_ptr&lt;const urdf::Link&gt;, int &gt; _maplinkindices;
</div>
<div class="parity0 source"><a href="#l1281" id="l1281">  1281</a>     std::map&lt; boost::shared_ptr&lt;const urdf::Material&gt;, int &gt; _mapmaterialindices;
</div>
<div class="parity1 source"><a href="#l1282" id="l1282">  1282</a>     Assimp::Importer _importer;
</div>
<div class="parity0 source"><a href="#l1283" id="l1283">  1283</a> };
</div>
<div class="parity1 source"><a href="#l1284" id="l1284">  1284</a> 
</div>
<div class="parity0 source"><a href="#l1285" id="l1285">  1285</a> 
</div>
<div class="parity1 source"><a href="#l1286" id="l1286">  1286</a> ColladaUrdfException::ColladaUrdfException(std::string const&amp; what)
</div>
<div class="parity0 source"><a href="#l1287" id="l1287">  1287</a>     : std::runtime_error(what)
</div>
<div class="parity1 source"><a href="#l1288" id="l1288">  1288</a> {
</div>
<div class="parity0 source"><a href="#l1289" id="l1289">  1289</a> }
</div>
<div class="parity1 source"><a href="#l1290" id="l1290">  1290</a> 
</div>
<div class="parity0 source"><a href="#l1291" id="l1291">  1291</a> bool colladaFromUrdfFile(string const&amp; file, boost::shared_ptr&lt;DAE&gt;&amp; dom) {
</div>
<div class="parity1 source"><a href="#l1292" id="l1292">  1292</a>     TiXmlDocument urdf_xml;
</div>
<div class="parity0 source"><a href="#l1293" id="l1293">  1293</a>     if (!urdf_xml.LoadFile(file)) {
</div>
<div class="parity1 source"><a href="#l1294" id="l1294">  1294</a>         ROS_ERROR(&quot;Could not load XML file&quot;);
</div>
<div class="parity0 source"><a href="#l1295" id="l1295">  1295</a>         return false;
</div>
<div class="parity1 source"><a href="#l1296" id="l1296">  1296</a>     }
</div>
<div class="parity0 source"><a href="#l1297" id="l1297">  1297</a> 
</div>
<div class="parity1 source"><a href="#l1298" id="l1298">  1298</a>     return colladaFromUrdfXml(&amp;urdf_xml, dom);
</div>
<div class="parity0 source"><a href="#l1299" id="l1299">  1299</a> }
</div>
<div class="parity1 source"><a href="#l1300" id="l1300">  1300</a> 
</div>
<div class="parity0 source"><a href="#l1301" id="l1301">  1301</a> bool colladaFromUrdfString(string const&amp; xml, boost::shared_ptr&lt;DAE&gt;&amp; dom) {
</div>
<div class="parity1 source"><a href="#l1302" id="l1302">  1302</a>     TiXmlDocument urdf_xml;
</div>
<div class="parity0 source"><a href="#l1303" id="l1303">  1303</a>     if (urdf_xml.Parse(xml.c_str()) == 0) {
</div>
<div class="parity1 source"><a href="#l1304" id="l1304">  1304</a>         ROS_ERROR(&quot;Could not parse XML document&quot;);
</div>
<div class="parity0 source"><a href="#l1305" id="l1305">  1305</a>         return false;
</div>
<div class="parity1 source"><a href="#l1306" id="l1306">  1306</a>     }
</div>
<div class="parity0 source"><a href="#l1307" id="l1307">  1307</a> 
</div>
<div class="parity1 source"><a href="#l1308" id="l1308">  1308</a>     return colladaFromUrdfXml(&amp;urdf_xml, dom);
</div>
<div class="parity0 source"><a href="#l1309" id="l1309">  1309</a> }
</div>
<div class="parity1 source"><a href="#l1310" id="l1310">  1310</a> 
</div>
<div class="parity0 source"><a href="#l1311" id="l1311">  1311</a> bool colladaFromUrdfXml(TiXmlDocument* xml_doc, boost::shared_ptr&lt;DAE&gt;&amp; dom) {
</div>
<div class="parity1 source"><a href="#l1312" id="l1312">  1312</a>     urdf::Model robot_model;
</div>
<div class="parity0 source"><a href="#l1313" id="l1313">  1313</a>     if (!robot_model.initXml(xml_doc)) {
</div>
<div class="parity1 source"><a href="#l1314" id="l1314">  1314</a>         ROS_ERROR(&quot;Could not generate robot model&quot;);
</div>
<div class="parity0 source"><a href="#l1315" id="l1315">  1315</a>         return false;
</div>
<div class="parity1 source"><a href="#l1316" id="l1316">  1316</a>     }
</div>
<div class="parity0 source"><a href="#l1317" id="l1317">  1317</a> 
</div>
<div class="parity1 source"><a href="#l1318" id="l1318">  1318</a>     return colladaFromUrdfModel(robot_model, dom);
</div>
<div class="parity0 source"><a href="#l1319" id="l1319">  1319</a> }
</div>
<div class="parity1 source"><a href="#l1320" id="l1320">  1320</a> 
</div>
<div class="parity0 source"><a href="#l1321" id="l1321">  1321</a> bool colladaFromUrdfModel(urdf::Model const&amp; robot_model, boost::shared_ptr&lt;DAE&gt;&amp; dom) {
</div>
<div class="parity1 source"><a href="#l1322" id="l1322">  1322</a>     ColladaWriter writer(robot_model,0);
</div>
<div class="parity0 source"><a href="#l1323" id="l1323">  1323</a>     dom = writer.convert();
</div>
<div class="parity1 source"><a href="#l1324" id="l1324">  1324</a>     return dom != boost::shared_ptr&lt;DAE&gt;();
</div>
<div class="parity0 source"><a href="#l1325" id="l1325">  1325</a> }
</div>
<div class="parity1 source"><a href="#l1326" id="l1326">  1326</a> 
</div>
<div class="parity0 source"><a href="#l1327" id="l1327">  1327</a> bool colladaToFile(boost::shared_ptr&lt;DAE&gt; dom, string const&amp; file) {
</div>
<div class="parity1 source"><a href="#l1328" id="l1328">  1328</a> 	daeString uri = dom-&gt;getDoc(0)-&gt;getDocumentURI()-&gt;getURI();
</div>
<div class="parity0 source"><a href="#l1329" id="l1329">  1329</a> 	return dom-&gt;writeTo(uri, file);
</div>
<div class="parity1 source"><a href="#l1330" id="l1330">  1330</a> }
</div>
<div class="parity0 source"><a href="#l1331" id="l1331">  1331</a> 
</div>
<div class="parity1 source"><a href="#l1332" id="l1332">  1332</a> }
</div>
<div class="sourcelast"></div>
</div>
</div>
</div>



</body>
</html>

