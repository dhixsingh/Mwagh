<html>
<head>
<title>main.cpp</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
.ln { color: #606366; font-weight: normal; font-style: normal; }
.s0 { color: rgb(187,181,41); }
.s1 { color: rgb(169,183,198); }
.s2 { color: rgb(106,135,89); }
.s3 { color: rgb(204,120,50); font-weight: bold; }
.s4 { color: rgb(204,120,50); }
.s5 { color: rgb(104,151,187); }
.s6 { color: rgb(128,128,128); }
</style>
</head>
<BODY BGCOLOR="#2b2b2b">
<TABLE CELLSPACING=0 CELLPADDING=5 COLS=1 WIDTH="100%" BGCOLOR="#606060" >
<TR><TD><CENTER>
<FONT FACE="Arial, Helvetica" COLOR="#000000">
main.cpp</FONT>
</center></TD></TR></TABLE>
<pre>
<span class="s0">#include </span><span class="s2">&lt;iostream&gt;</span><span class="s1"> 
</span><span class="s0">#include </span><span class="s2">&lt;math.h&gt;</span><span class="s1"> 
 
</span><span class="s3">using namespace </span><span class="s1">std</span><span class="s4">;</span><span class="s1"> 
 
 
</span><span class="s3">struct </span><span class="s1">stock { 
    </span><span class="s3">long long </span><span class="s1">id</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">price</span><span class="s4">;</span><span class="s1"> 
}</span><span class="s4">;</span><span class="s1"> 
 
</span><span class="s3">void </span><span class="s1">conquer(stock arr[]</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">p</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">q</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">r) { 
    </span><span class="s3">long long </span><span class="s1">n1 = q - p + </span><span class="s5">1</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">n2 = r - q</span><span class="s4">;</span><span class="s1"> 
 
    stock A[n1]</span><span class="s4">, </span><span class="s1">B[n2]</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">for </span><span class="s1">(</span><span class="s3">long long </span><span class="s1">i = </span><span class="s5">0</span><span class="s4">; </span><span class="s1">i &lt; n1</span><span class="s4">; </span><span class="s1">i++) 
        A[i] = arr[p + i]</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">for </span><span class="s1">(</span><span class="s3">long long </span><span class="s1">j = </span><span class="s5">0</span><span class="s4">; </span><span class="s1">j &lt; n2</span><span class="s4">; </span><span class="s1">j++) 
        B[j] = arr[q + </span><span class="s5">1 </span><span class="s1">+ j]</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">long long </span><span class="s1">i = </span><span class="s5">0</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">j = </span><span class="s5">0</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">k = p</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">while </span><span class="s1">(i &lt; n1 &amp;&amp; j &lt; n2) { 
        </span><span class="s3">if </span><span class="s1">(A[i].id &lt;= B[j].id) { 
            arr[k] = A[i]</span><span class="s4">;</span><span class="s1"> 
            i++</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else </span><span class="s1">{ 
            arr[k] = B[j]</span><span class="s4">;</span><span class="s1"> 
            j++</span><span class="s4">;</span><span class="s1"> 
        } 
        k++</span><span class="s4">;</span><span class="s1"> 
    } 
    </span><span class="s3">while </span><span class="s1">(i &lt; n1) { 
        arr[k] = A[i]</span><span class="s4">;</span><span class="s1"> 
        i++</span><span class="s4">;</span><span class="s1"> 
        k++</span><span class="s4">;</span><span class="s1"> 
    } 
    </span><span class="s3">while </span><span class="s1">(j &lt; n2) { 
        arr[k] = B[j]</span><span class="s4">;</span><span class="s1"> 
        j++</span><span class="s4">;</span><span class="s1"> 
        k++</span><span class="s4">;</span><span class="s1"> 
    } 
} 
 
</span><span class="s3">void </span><span class="s1">divide(stock arr[]</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">y</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">z) { 
    </span><span class="s3">if </span><span class="s1">(y &lt; z) { 
        </span><span class="s3">long long </span><span class="s1">x = y + (z - y) / </span><span class="s5">2</span><span class="s4">;</span><span class="s1"> 
 
        divide(arr</span><span class="s4">, </span><span class="s1">y</span><span class="s4">, </span><span class="s1">x)</span><span class="s4">;</span><span class="s1"> 
        divide(arr</span><span class="s4">, </span><span class="s1">x + </span><span class="s5">1</span><span class="s4">, </span><span class="s1">z)</span><span class="s4">;</span><span class="s1"> 
 
        conquer(arr</span><span class="s4">, </span><span class="s1">y</span><span class="s4">, </span><span class="s1">x</span><span class="s4">, </span><span class="s1">z)</span><span class="s4">;</span><span class="s1"> 
    } 
} 
 
</span><span class="s3">void </span><span class="s1">printarr(stock arr[]</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">size) { 
    </span><span class="s3">for </span><span class="s1">(</span><span class="s3">long long </span><span class="s1">i = </span><span class="s5">0</span><span class="s4">; </span><span class="s1">i &lt; size</span><span class="s4">; </span><span class="s1">i++) { 
        cout &lt;&lt; arr[i].id &lt;&lt; </span><span class="s2">&quot; &quot; </span><span class="s1">&lt;&lt; arr[i].price &lt;&lt; endl</span><span class="s4">;</span><span class="s1"> 
    } 
} 
 
</span><span class="s3">struct </span><span class="s1">Node { 
    stock key</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">struct </span><span class="s1">Node *left = </span><span class="s3">nullptr</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">struct </span><span class="s1">Node *right = </span><span class="s3">nullptr</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">height</span><span class="s4">;</span><span class="s1"> 
}</span><span class="s4">;</span><span class="s1"> 
 
</span><span class="s3">long long </span><span class="s1">height(</span><span class="s3">struct </span><span class="s1">Node *N) { 
    </span><span class="s3">if </span><span class="s1">(N == </span><span class="s3">nullptr</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s5">0</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">else</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">N-&gt;height</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">long long </span><span class="s1">maximum(</span><span class="s3">long long </span><span class="s1">a</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">b) { 
    </span><span class="s3">if </span><span class="s1">(a &gt; b) 
        </span><span class="s3">return </span><span class="s1">a</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">else</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">b</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *newNode(stock key) { 
    </span><span class="s3">struct </span><span class="s1">Node *node = </span><span class="s3">new </span><span class="s1">(</span><span class="s3">struct </span><span class="s1">Node)</span><span class="s4">;</span><span class="s1"> 
    node-&gt;key = key</span><span class="s4">;</span><span class="s1"> 
    node-&gt;height = </span><span class="s5">1</span><span class="s4">;</span><span class="s1"> 
    node-&gt;left = </span><span class="s3">nullptr</span><span class="s4">;</span><span class="s1"> 
    node-&gt;right = </span><span class="s3">nullptr</span><span class="s4">;</span><span class="s6">// new node is initially added at leaf</span><span class="s1"> 
    </span><span class="s3">return </span><span class="s1">(node)</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *rRot(</span><span class="s3">struct </span><span class="s1">Node *y) { 
    </span><span class="s3">struct </span><span class="s1">Node *x = y-&gt;left</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">struct </span><span class="s1">Node *T2 = x-&gt;right</span><span class="s4">;</span><span class="s1"> 
 
    x-&gt;right = y</span><span class="s4">;</span><span class="s1"> 
    y-&gt;left = T2</span><span class="s4">;</span><span class="s1"> 
 
    y-&gt;height = maximum(height(y-&gt;left)</span><span class="s4">, </span><span class="s1">height(y-&gt;right)) + </span><span class="s5">1</span><span class="s4">;</span><span class="s1"> 
    x-&gt;height = maximum(height(x-&gt;left)</span><span class="s4">, </span><span class="s1">height(x-&gt;right)) + </span><span class="s5">1</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">return </span><span class="s1">x</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *lRot(</span><span class="s3">struct </span><span class="s1">Node *x) { 
    </span><span class="s3">struct </span><span class="s1">Node *y = x-&gt;right</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">struct </span><span class="s1">Node *T2 = y-&gt;left</span><span class="s4">;</span><span class="s1"> 
 
    y-&gt;left = x</span><span class="s4">;</span><span class="s1"> 
    x-&gt;right = T2</span><span class="s4">;</span><span class="s1"> 
 
    x-&gt;height = maximum(height(x-&gt;left)</span><span class="s4">, </span><span class="s1">height(x-&gt;right)) + </span><span class="s5">1</span><span class="s4">;</span><span class="s1"> 
    y-&gt;height = maximum(height(y-&gt;left)</span><span class="s4">, </span><span class="s1">height(y-&gt;right)) + </span><span class="s5">1</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">return </span><span class="s1">y</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">long long </span><span class="s1">balance(</span><span class="s3">struct </span><span class="s1">Node *node) { 
    </span><span class="s3">if </span><span class="s1">(node == </span><span class="s3">nullptr</span><span class="s1">) { 
        </span><span class="s3">return </span><span class="s5">0</span><span class="s4">;</span><span class="s1"> 
    } </span><span class="s3">else</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">height(node-&gt;left) - height(node-&gt;right)</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *min(</span><span class="s3">struct </span><span class="s1">Node *rand) { 
    </span><span class="s3">struct </span><span class="s1">Node *pointer = rand</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">while </span><span class="s1">(pointer-&gt;left != </span><span class="s3">nullptr</span><span class="s1">) 
        pointer = pointer-&gt;left</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">return </span><span class="s1">pointer</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *reg(</span><span class="s3">struct </span><span class="s1">Node *node</span><span class="s4">, </span><span class="s1">stock key) { 
    </span><span class="s3">if </span><span class="s1">(node == </span><span class="s3">nullptr</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">(newNode(key))</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">if </span><span class="s1">(key.id &lt; node-&gt;key.id) { 
        node-&gt;left = reg(node-&gt;left</span><span class="s4">, </span><span class="s1">key)</span><span class="s4">;</span><span class="s1"> 
    } </span><span class="s3">else if </span><span class="s1">(key.id &gt; node-&gt;key.id) { 
        node-&gt;right = reg(node-&gt;right</span><span class="s4">, </span><span class="s1">key)</span><span class="s4">;</span><span class="s1"> 
    } </span><span class="s3">else</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">node</span><span class="s4">;</span><span class="s1"> 
    node-&gt;height = </span><span class="s5">1 </span><span class="s1">+ maximum(height(node-&gt;left)</span><span class="s4">, </span><span class="s1">height(node-&gt;right))</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">bal = balance(node)</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">if </span><span class="s1">(bal &gt; </span><span class="s5">1 </span><span class="s1">&amp;&amp; key.id &lt; node-&gt;left-&gt;key.id) 
        </span><span class="s3">return </span><span class="s1">rRot(node)</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">if </span><span class="s1">(bal &lt; -</span><span class="s5">1 </span><span class="s1">&amp;&amp; key.id &gt; node-&gt;right-&gt;key.id) 
        </span><span class="s3">return </span><span class="s1">lRot(node)</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">if </span><span class="s1">(bal &gt; </span><span class="s5">1 </span><span class="s1">&amp;&amp; key.id &gt; node-&gt;left-&gt;key.id) { 
        node-&gt;left = lRot(node-&gt;left)</span><span class="s4">;</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">rRot(node)</span><span class="s4">;</span><span class="s1"> 
    } 
 
    </span><span class="s3">if </span><span class="s1">(bal &lt; -</span><span class="s5">1 </span><span class="s1">&amp;&amp; key.id &lt; node-&gt;right-&gt;key.id) { 
        node-&gt;right = rRot(node-&gt;right)</span><span class="s4">;</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">lRot(node)</span><span class="s4">;</span><span class="s1"> 
    } 
 
    </span><span class="s3">return </span><span class="s1">node</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *dereg(</span><span class="s3">struct </span><span class="s1">Node *node</span><span class="s4">, </span><span class="s1">stock key) { 
    </span><span class="s3">if </span><span class="s1">(node == </span><span class="s3">nullptr</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">node</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">if </span><span class="s1">(key.id &lt; node-&gt;key.id) { 
        node-&gt;left = dereg(node-&gt;left</span><span class="s4">, </span><span class="s1">key)</span><span class="s4">;</span><span class="s1"> 
    } </span><span class="s3">else if </span><span class="s1">(key.id &gt; node-&gt;key.id) { 
        node-&gt;right = dereg(node-&gt;right</span><span class="s4">, </span><span class="s1">key)</span><span class="s4">;</span><span class="s1"> 
    } </span><span class="s3">else </span><span class="s1">{ 
        </span><span class="s3">struct </span><span class="s1">Node *temp1</span><span class="s4">;</span><span class="s1"> 
        </span><span class="s3">if </span><span class="s1">(node-&gt;left == </span><span class="s3">nullptr </span><span class="s1">&amp;&amp; node-&gt;right == </span><span class="s3">nullptr</span><span class="s1">) { 
            node = </span><span class="s3">nullptr</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(node-&gt;left == </span><span class="s3">nullptr</span><span class="s1">) { 
            temp1 = node</span><span class="s4">;</span><span class="s1"> 
            node = node-&gt;right</span><span class="s4">;</span><span class="s1"> 
            free(temp1)</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(node-&gt;right == </span><span class="s3">nullptr</span><span class="s1">) { 
            temp1 = node</span><span class="s4">;</span><span class="s1"> 
            node = node-&gt;left</span><span class="s4">;</span><span class="s1"> 
            free(temp1)</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else </span><span class="s1">{ 
            </span><span class="s3">struct </span><span class="s1">Node *temp = min(node-&gt;right)</span><span class="s4">;</span><span class="s1"> 
            node-&gt;key = temp-&gt;key</span><span class="s4">;</span><span class="s1"> 
            node-&gt;right = dereg(node-&gt;right</span><span class="s4">, </span><span class="s1">temp-&gt;key)</span><span class="s4">;</span><span class="s1"> 
        } 
    } 
    </span><span class="s3">if </span><span class="s1">(node == </span><span class="s3">nullptr</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">node</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">bal = balance(node)</span><span class="s4">;</span><span class="s1"> 
    node-&gt;height = </span><span class="s5">1 </span><span class="s1">+ maximum(height(node-&gt;left)</span><span class="s4">, </span><span class="s1">height(node-&gt;right))</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">if </span><span class="s1">(bal &gt; </span><span class="s5">1 </span><span class="s1">&amp;&amp; balance(node-&gt;left) &gt;= </span><span class="s5">0</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">rRot(node)</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">if </span><span class="s1">(bal &gt; </span><span class="s5">1 </span><span class="s1">&amp;&amp; balance(node-&gt;left) &lt; </span><span class="s5">0</span><span class="s1">) { 
        node-&gt;left = lRot(node-&gt;left)</span><span class="s4">;</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">rRot(node)</span><span class="s4">;</span><span class="s1"> 
    } 
    </span><span class="s3">if </span><span class="s1">(bal &lt; -</span><span class="s5">1 </span><span class="s1">&amp;&amp; balance(node-&gt;right) &lt;= </span><span class="s5">0</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">lRot(node)</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">if </span><span class="s1">(bal &lt; -</span><span class="s5">1 </span><span class="s1">&amp;&amp; balance(node-&gt;right) &gt; </span><span class="s5">0</span><span class="s1">) { 
        node-&gt;right = rRot(node-&gt;right)</span><span class="s4">;</span><span class="s1"> 
        </span><span class="s3">return </span><span class="s1">lRot(node)</span><span class="s4">;</span><span class="s1"> 
    } 
    </span><span class="s3">return </span><span class="s1">node</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *update(</span><span class="s3">struct </span><span class="s1">Node *root</span><span class="s4">, </span><span class="s1">stock input</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">threshold) { 
    Node *current = root</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">while </span><span class="s1">(current != </span><span class="s3">nullptr </span><span class="s1">&amp;&amp; current-&gt;key.id != input.id) { 
        </span><span class="s3">if </span><span class="s1">(current-&gt;key.id &gt; input.id) { 
</span><span class="s6">//            if (current-&gt;left == nullptr)</span><span class="s1"> 
</span><span class="s6">//                return root;</span><span class="s1"> 
</span><span class="s6">//            else</span><span class="s1"> 
                current = current-&gt;left</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(current-&gt;key.id &lt; input.id) { 
</span><span class="s6">//            if (current-&gt;right == nullptr)</span><span class="s1"> 
</span><span class="s6">//                return root;</span><span class="s1"> 
</span><span class="s6">//            else</span><span class="s1"> 
                current = current-&gt;right</span><span class="s4">;</span><span class="s1"> 
        } 
    } 
    </span><span class="s3">if </span><span class="s1">(current == </span><span class="s3">nullptr</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">else </span><span class="s1">{ 
        </span><span class="s3">if </span><span class="s1">(abs(current-&gt;key.price - input.price) &gt; threshold) { 
            current-&gt;key.price = input.price</span><span class="s4">;</span><span class="s1"> 
            cout &lt;&lt; current-&gt;key.id &lt;&lt; </span><span class="s2">&quot; &quot; </span><span class="s1">&lt;&lt; current-&gt;key.price &lt;&lt; endl</span><span class="s4">;</span><span class="s1"> 
        } 
    } 
    </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
} 
 
 
</span><span class="s3">struct </span><span class="s1">Node *split(</span><span class="s3">struct </span><span class="s1">Node *root</span><span class="s4">, </span><span class="s1">stock input</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">threshold</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">y</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">z) { 
    Node *current = root</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">while </span><span class="s1">(current-&gt;key.id != input.id &amp;&amp; current != </span><span class="s3">nullptr</span><span class="s1">) { 
        </span><span class="s3">if </span><span class="s1">(current-&gt;key.id &gt; input.id) { 
            </span><span class="s3">if </span><span class="s1">(current-&gt;left == </span><span class="s3">nullptr</span><span class="s1">) 
                </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
            </span><span class="s3">else</span><span class="s1"> 
                current = current-&gt;left</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(current-&gt;key.id &lt; input.id) { 
            </span><span class="s3">if </span><span class="s1">(current-&gt;right == </span><span class="s3">nullptr</span><span class="s1">) 
                </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
            </span><span class="s3">else</span><span class="s1"> 
                current = current-&gt;right</span><span class="s4">;</span><span class="s1"> 
        } 
    } 
    </span><span class="s3">if </span><span class="s1">(current == </span><span class="s3">nullptr</span><span class="s1">) 
        </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">else </span><span class="s1">{ 
 
        current-&gt;key.price = (current-&gt;key.price * z) / y</span><span class="s4">;</span><span class="s1"> 
        cout &lt;&lt; current-&gt;key.id &lt;&lt; </span><span class="s2">&quot; &quot; </span><span class="s1">&lt;&lt; current-&gt;key.price &lt;&lt; endl</span><span class="s4">;</span><span class="s1"> 
    } 
    </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">void </span><span class="s1">printlist(</span><span class="s3">struct </span><span class="s1">Node *root) { 
    </span><span class="s3">if </span><span class="s1">(root != </span><span class="s3">nullptr</span><span class="s1">) { 
        cout &lt;&lt; root-&gt;key.id &lt;&lt; </span><span class="s2">&quot; &quot; </span><span class="s1">&lt;&lt; root-&gt;key.price &lt;&lt; endl</span><span class="s4">;</span><span class="s1"> 
        printlist(root-&gt;left)</span><span class="s4">;</span><span class="s1"> 
        printlist(root-&gt;right)</span><span class="s4">;</span><span class="s1"> 
    } 
} 
 
</span><span class="s3">struct </span><span class="s1">Node *transfer(stock arr[]</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">a</span><span class="s4">, </span><span class="s3">long long </span><span class="s1">b) { 
    </span><span class="s3">if </span><span class="s1">(a &gt; b) 
        </span><span class="s3">return nullptr</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">mid = (a + b) / </span><span class="s5">2</span><span class="s4">;</span><span class="s1"> 
 
    </span><span class="s3">struct </span><span class="s1">Node *root = newNode(arr[mid])</span><span class="s4">;</span><span class="s1"> 
    root-&gt;left = transfer(arr</span><span class="s4">, </span><span class="s1">a</span><span class="s4">, </span><span class="s1">mid - </span><span class="s5">1</span><span class="s1">)</span><span class="s4">;</span><span class="s1"> 
    root-&gt;right = transfer(arr</span><span class="s4">, </span><span class="s1">mid + </span><span class="s5">1</span><span class="s4">, </span><span class="s1">b)</span><span class="s4">;</span><span class="s1"> 
    root-&gt;height = </span><span class="s5">1 </span><span class="s1">+ max(height(root-&gt;left)</span><span class="s4">, </span><span class="s1">height(root-&gt;right))</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">return </span><span class="s1">root</span><span class="s4">;</span><span class="s1"> 
} 
 
</span><span class="s3">int </span><span class="s1">main() { 
    </span><span class="s3">long long </span><span class="s1">size</span><span class="s4">;</span><span class="s1"> 
    cin &gt;&gt; size</span><span class="s4">;</span><span class="s1"> 
    stock arr[size]</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">i</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">struct </span><span class="s1">Node *root = </span><span class="s3">nullptr</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">for </span><span class="s1">(i = </span><span class="s5">0</span><span class="s4">; </span><span class="s1">i &lt; size</span><span class="s4">; </span><span class="s1">i++) { 
        cin &gt;&gt; arr[i].id</span><span class="s4">;</span><span class="s1"> 
        cin &gt;&gt; arr[i].price</span><span class="s4">;</span><span class="s1"> 
    } 
    divide(arr</span><span class="s4">, </span><span class="s5">0</span><span class="s4">, </span><span class="s1">size - </span><span class="s5">1</span><span class="s1">)</span><span class="s4">;</span><span class="s1"> 
</span><span class="s6">//    printarr(arr, size);</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">currheight</span><span class="s4">;</span><span class="s1"> 
    root = transfer(arr</span><span class="s4">, </span><span class="s5">0</span><span class="s4">, </span><span class="s1">size - </span><span class="s5">1</span><span class="s1">)</span><span class="s4">;</span><span class="s1"> 
</span><span class="s6">//   printlist(root);</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">operations</span><span class="s4">;</span><span class="s1"> 
    cin &gt;&gt; operations</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">long long </span><span class="s1">threshold</span><span class="s4">;</span><span class="s1"> 
    cin &gt;&gt; threshold</span><span class="s4">;</span><span class="s1"> 
    </span><span class="s3">for </span><span class="s1">(i = </span><span class="s5">0</span><span class="s4">; </span><span class="s1">i &lt; operations</span><span class="s4">; </span><span class="s1">i++) { 
        </span><span class="s3">long long </span><span class="s1">a</span><span class="s4">;</span><span class="s1"> 
        cin &gt;&gt; a</span><span class="s4">;</span><span class="s1"> 
        </span><span class="s3">if </span><span class="s1">(a == </span><span class="s5">1</span><span class="s1">) { 
            stock p</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; p.id</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; p.price</span><span class="s4">;</span><span class="s1"> 
            cout &lt;&lt; p.id &lt;&lt; </span><span class="s2">&quot; &quot; </span><span class="s1">&lt;&lt; p.price &lt;&lt; endl</span><span class="s4">;</span><span class="s1"> 
            root = reg(root</span><span class="s4">, </span><span class="s1">p)</span><span class="s4">;</span><span class="s1"> 
</span><span class="s6">//            printlist(root);</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(a == </span><span class="s5">2</span><span class="s1">) { 
            stock p</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; p.id</span><span class="s4">;</span><span class="s1"> 
            root = dereg(root</span><span class="s4">, </span><span class="s1">p)</span><span class="s4">;</span><span class="s1"> 
            </span><span class="s6">//       printlist(root);</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(a == </span><span class="s5">3</span><span class="s1">) { 
            stock p</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; p.id</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; p.price</span><span class="s4">;</span><span class="s1"> 
            update(root</span><span class="s4">, </span><span class="s1">p</span><span class="s4">, </span><span class="s1">threshold)</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(a == </span><span class="s5">4</span><span class="s1">) { 
            stock p</span><span class="s4">;</span><span class="s1"> 
            </span><span class="s3">long long </span><span class="s1">y</span><span class="s4">, </span><span class="s1">z</span><span class="s4">;</span><span class="s1"> 
            </span><span class="s3">char </span><span class="s1">random</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; p.id</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; y</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; random</span><span class="s4">;</span><span class="s1"> 
            cin &gt;&gt; z</span><span class="s4">;</span><span class="s1"> 
            split(root</span><span class="s4">, </span><span class="s1">p</span><span class="s4">, </span><span class="s1">threshold</span><span class="s4">, </span><span class="s1">y</span><span class="s4">, </span><span class="s1">z)</span><span class="s4">;</span><span class="s1"> 
        } </span><span class="s3">else if </span><span class="s1">(a == </span><span class="s5">5</span><span class="s1">) { 
            printlist(root)</span><span class="s4">;</span><span class="s1"> 
        } 
 
</span><span class="s6">//        else if (a == 2){</span><span class="s1"> 
</span><span class="s6">//            deletion;</span><span class="s1"> 
</span><span class="s6">//        }</span><span class="s1"> 
</span><span class="s6">//        else if (a == 3){</span><span class="s1"> 
</span><span class="s6">//            update;</span><span class="s1"> 
</span><span class="s6">//        }</span><span class="s1"> 
</span><span class="s6">//        else if (a == 4){</span><span class="s1"> 
</span><span class="s6">//            split;</span><span class="s1"> 
</span><span class="s6">//        }</span><span class="s1"> 
</span><span class="s6">//    }</span><span class="s1"> 
    } 
    </span><span class="s3">return </span><span class="s5">0</span><span class="s4">;</span><span class="s1"> 
}</span></pre>
</body>
</html>