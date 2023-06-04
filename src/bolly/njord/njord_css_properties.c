/*
 * Copyright (c) 2023 Netlore Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * This code is part of Njord (HTML, CSS Parser) Component
 * of Netlore project that can be found at the github
 * repository at:
 *  - https://github.com/netlore-org/netlore
 */

#include <netlore/netlore.h>
#include <netlore/netlore_utils.h>

#include <netlore/bolly/njord/njord_css_properties.h>

css_properties_t
njord_parse_css_property(char* css_string_property)
{
    /* Change this string to lower characters */
    netlore_to_lower_string(css_string_property);

	if (strcmp(css_string_property, "-webkit-line-clamp") == 0)
		return WebkitLineClamp;
	if (strcmp(css_string_property, "accent-color") == 0)
		return AccentColor;
	if (strcmp(css_string_property, "align-content") == 0)
		return AlignContent;
	if (strcmp(css_string_property, "align-items") == 0)
		return AlignItems;
	if (strcmp(css_string_property, "align-self") == 0)
		return AlignSelf;
	if (strcmp(css_string_property, "alignment-baseline") == 0)
		return AlignmentBaseline;
	if (strcmp(css_string_property, "all") == 0)
		return All;
	if (strcmp(css_string_property, "animation") == 0)
		return Animation;
	if (strcmp(css_string_property, "animation-composition") == 0)
		return AnimationComposition;
	if (strcmp(css_string_property, "animation-delay") == 0)
		return AnimationDelay;
	if (strcmp(css_string_property, "animation-direction") == 0)
		return AnimationDirection;
	if (strcmp(css_string_property, "animation-duration") == 0)
		return AnimationDuration;
	if (strcmp(css_string_property, "animation-fill-mode") == 0)
		return AnimationFillMode;
	if (strcmp(css_string_property, "animation-iteration-count") == 0)
		return AnimationIterationCount;
	if (strcmp(css_string_property, "animation-name") == 0)
		return AnimationName;
	if (strcmp(css_string_property, "animation-play-state") == 0)
		return AnimationPlayState;
	if (strcmp(css_string_property, "animation-range") == 0)
		return AnimationRange;
	if (strcmp(css_string_property, "animation-range-end") == 0)
		return AnimationRangeEnd;
	if (strcmp(css_string_property, "animation-range-start") == 0)
		return AnimationRangeStart;
	if (strcmp(css_string_property, "animation-timeline") == 0)
		return AnimationTimeline;
	if (strcmp(css_string_property, "animation-timing-function") == 0)
		return AnimationTimingFunction;
	if (strcmp(css_string_property, "appearance") == 0)
		return Appearance;
	if (strcmp(css_string_property, "aspect-ratio") == 0)
		return AspectRatio;
	if (strcmp(css_string_property, "azimuth") == 0)
		return Azimuth;
	if (strcmp(css_string_property, "backface-visibility") == 0)
		return BackfaceVisibility;
	if (strcmp(css_string_property, "background") == 0)
		return Background;
	if (strcmp(css_string_property, "background-attachment") == 0)
		return BackgroundAttachment;
	if (strcmp(css_string_property, "background-blend-mode") == 0)
		return BackgroundBlendMode;
	if (strcmp(css_string_property, "background-clip") == 0)
		return BackgroundClip;
	if (strcmp(css_string_property, "background-color") == 0)
		return BackgroundColor;
	if (strcmp(css_string_property, "background-image") == 0)
		return BackgroundImage;
	if (strcmp(css_string_property, "background-origin") == 0)
		return BackgroundOrigin;
	if (strcmp(css_string_property, "background-position") == 0)
		return BackgroundPosition;
	if (strcmp(css_string_property, "background-repeat") == 0)
		return BackgroundRepeat;
	if (strcmp(css_string_property, "background-size") == 0)
		return BackgroundSize;
	if (strcmp(css_string_property, "baseline-shift") == 0)
		return BaselineShift;
	if (strcmp(css_string_property, "baseline-source") == 0)
		return BaselineSource;
	if (strcmp(css_string_property, "block-ellipsis") == 0)
		return BlockEllipsis;
	if (strcmp(css_string_property, "block-size") == 0)
		return BlockSize;
	if (strcmp(css_string_property, "block-step") == 0)
		return BlockStep;
	if (strcmp(css_string_property, "block-step-align") == 0)
		return BlockStepAlign;
	if (strcmp(css_string_property, "block-step-insert") == 0)
		return BlockStepInsert;
	if (strcmp(css_string_property, "block-step-round") == 0)
		return BlockStepRound;
	if (strcmp(css_string_property, "block-step-size") == 0)
		return BlockStepSize;
	if (strcmp(css_string_property, "bookmark-label") == 0)
		return BookmarkLabel;
	if (strcmp(css_string_property, "bookmark-level") == 0)
		return BookmarkLevel;
	if (strcmp(css_string_property, "bookmark-state") == 0)
		return BookmarkState;
	if (strcmp(css_string_property, "border") == 0)
		return Border;
	if (strcmp(css_string_property, "border-block") == 0)
		return BorderBlock;
	if (strcmp(css_string_property, "border-block-color") == 0)
		return BorderBlockColor;
	if (strcmp(css_string_property, "border-block-end") == 0)
		return BorderBlockEnd;
	if (strcmp(css_string_property, "border-block-end-color") == 0)
		return BorderBlockEndColor;
	if (strcmp(css_string_property, "border-block-end-style") == 0)
		return BorderBlockEndStyle;
	if (strcmp(css_string_property, "border-block-end-width") == 0)
		return BorderBlockEndWidth;
	if (strcmp(css_string_property, "border-block-start") == 0)
		return BorderBlockStart;
	if (strcmp(css_string_property, "border-block-start-color") == 0)
		return BorderBlockStartColor;
	if (strcmp(css_string_property, "border-block-start-style") == 0)
		return BorderBlockStartStyle;
	if (strcmp(css_string_property, "border-block-start-width") == 0)
		return BorderBlockStartWidth;
	if (strcmp(css_string_property, "border-block-style") == 0)
		return BorderBlockStyle;
	if (strcmp(css_string_property, "border-block-width") == 0)
		return BorderBlockWidth;
	if (strcmp(css_string_property, "border-bottom") == 0)
		return BorderBottom;
	if (strcmp(css_string_property, "border-bottom-color") == 0)
		return BorderBottomColor;
	if (strcmp(css_string_property, "border-bottom-left-radius") == 0)
		return BorderBottomLeftRadius;
	if (strcmp(css_string_property, "border-bottom-right-radius") == 0)
		return BorderBottomRightRadius;
	if (strcmp(css_string_property, "border-bottom-style") == 0)
		return BorderBottomStyle;
	if (strcmp(css_string_property, "border-bottom-width") == 0)
		return BorderBottomWidth;
	if (strcmp(css_string_property, "border-boundary") == 0)
		return BorderBoundary;
	if (strcmp(css_string_property, "border-collapse") == 0)
		return BorderCollapse;
	if (strcmp(css_string_property, "border-color") == 0)
		return BorderColor;
	if (strcmp(css_string_property, "border-end-end-radius") == 0)
		return BorderEndEndRadius;
	if (strcmp(css_string_property, "border-end-start-radius") == 0)
		return BorderEndStartRadius;
	if (strcmp(css_string_property, "border-image") == 0)
		return BorderImage;
	if (strcmp(css_string_property, "border-image-outset") == 0)
		return BorderImageOutset;
	if (strcmp(css_string_property, "border-image-repeat") == 0)
		return BorderImageRepeat;
	if (strcmp(css_string_property, "border-image-slice") == 0)
		return BorderImageSlice;
	if (strcmp(css_string_property, "border-image-source") == 0)
		return BorderImageSource;
	if (strcmp(css_string_property, "border-image-width") == 0)
		return BorderImageWidth;
	if (strcmp(css_string_property, "border-inline") == 0)
		return BorderInline;
	if (strcmp(css_string_property, "border-inline-color") == 0)
		return BorderInlineColor;
	if (strcmp(css_string_property, "border-inline-end") == 0)
		return BorderInlineEnd;
	if (strcmp(css_string_property, "border-inline-end-color") == 0)
		return BorderInlineEndColor;
	if (strcmp(css_string_property, "border-inline-end-style") == 0)
		return BorderInlineEndStyle;
	if (strcmp(css_string_property, "border-inline-end-width") == 0)
		return BorderInlineEndWidth;
	if (strcmp(css_string_property, "border-inline-start") == 0)
		return BorderInlineStart;
	if (strcmp(css_string_property, "border-inline-start-color") == 0)
		return BorderInlineStartColor;
	if (strcmp(css_string_property, "border-inline-start-style") == 0)
		return BorderInlineStartStyle;
	if (strcmp(css_string_property, "border-inline-start-width") == 0)
		return BorderInlineStartWidth;
	if (strcmp(css_string_property, "border-inline-style") == 0)
		return BorderInlineStyle;
	if (strcmp(css_string_property, "border-inline-width") == 0)
		return BorderInlineWidth;
	if (strcmp(css_string_property, "border-left") == 0)
		return BorderLeft;
	if (strcmp(css_string_property, "border-left-color") == 0)
		return BorderLeftColor;
	if (strcmp(css_string_property, "border-left-style") == 0)
		return BorderLeftStyle;
	if (strcmp(css_string_property, "border-left-width") == 0)
		return BorderLeftWidth;
	if (strcmp(css_string_property, "border-radius") == 0)
		return BorderRadius;
	if (strcmp(css_string_property, "border-right") == 0)
		return BorderRight;
	if (strcmp(css_string_property, "border-right-color") == 0)
		return BorderRightColor;
	if (strcmp(css_string_property, "border-right-style") == 0)
		return BorderRightStyle;
	if (strcmp(css_string_property, "border-right-width") == 0)
		return BorderRightWidth;
	if (strcmp(css_string_property, "border-spacing") == 0)
		return BorderSpacing;
	if (strcmp(css_string_property, "border-start-end-radius") == 0)
		return BorderStartEndRadius;
	if (strcmp(css_string_property, "border-start-start-radius") == 0)
		return BorderStartStartRadius;
	if (strcmp(css_string_property, "border-style") == 0)
		return BorderStyle;
	if (strcmp(css_string_property, "border-top") == 0)
		return BorderTop;
	if (strcmp(css_string_property, "border-top-color") == 0)
		return BorderTopColor;
	if (strcmp(css_string_property, "border-top-left-radius") == 0)
		return BorderTopLeftRadius;
	if (strcmp(css_string_property, "border-top-right-radius") == 0)
		return BorderTopRightRadius;
	if (strcmp(css_string_property, "border-top-style") == 0)
		return BorderTopStyle;
	if (strcmp(css_string_property, "border-top-width") == 0)
		return BorderTopWidth;
	if (strcmp(css_string_property, "border-width") == 0)
		return BorderWidth;
	if (strcmp(css_string_property, "bottom") == 0)
		return Bottom;
	if (strcmp(css_string_property, "box-decoration-break") == 0)
		return BoxDecorationBreak;
	if (strcmp(css_string_property, "box-shadow") == 0)
		return BoxShadow;
	if (strcmp(css_string_property, "box-sizing") == 0)
		return BoxSizing;
	if (strcmp(css_string_property, "box-snap") == 0)
		return BoxSnap;
	if (strcmp(css_string_property, "break-after") == 0)
		return BreakAfter;
	if (strcmp(css_string_property, "break-before") == 0)
		return BreakBefore;
	if (strcmp(css_string_property, "break-inside") == 0)
		return BreakInside;
	if (strcmp(css_string_property, "caption-side") == 0)
		return CaptionSide;
	if (strcmp(css_string_property, "caret") == 0)
		return Caret;
	if (strcmp(css_string_property, "caret-color") == 0)
		return CaretColor;
	if (strcmp(css_string_property, "caret-shape") == 0)
		return CaretShape;
	if (strcmp(css_string_property, "chains") == 0)
		return Chains;
	if (strcmp(css_string_property, "clear") == 0)
		return Clear;
	if (strcmp(css_string_property, "clip") == 0)
		return Clip;
	if (strcmp(css_string_property, "clip-path") == 0)
		return ClipPath;
	if (strcmp(css_string_property, "clip-rule") == 0)
		return ClipRule;
	if (strcmp(css_string_property, "color") == 0)
		return Color;
	if (strcmp(css_string_property, "color-adjust") == 0)
		return ColorAdjust;
	if (strcmp(css_string_property, "color-interpolation-filters") == 0)
		return ColorInterpolationFilters;
	if (strcmp(css_string_property, "color-scheme") == 0)
		return ColorScheme;
	if (strcmp(css_string_property, "column-count") == 0)
		return ColumnCount;
	if (strcmp(css_string_property, "column-fill") == 0)
		return ColumnFill;
	if (strcmp(css_string_property, "column-gap") == 0)
		return ColumnGap;
	if (strcmp(css_string_property, "column-rule") == 0)
		return ColumnRule;
	if (strcmp(css_string_property, "column-rule-color") == 0)
		return ColumnRuleColor;
	if (strcmp(css_string_property, "column-rule-style") == 0)
		return ColumnRuleStyle;
	if (strcmp(css_string_property, "column-rule-width") == 0)
		return ColumnRuleWidth;
	if (strcmp(css_string_property, "column-span") == 0)
		return ColumnSpan;
	if (strcmp(css_string_property, "column-width") == 0)
		return ColumnWidth;
	if (strcmp(css_string_property, "columns") == 0)
		return Columns;
	if (strcmp(css_string_property, "contain") == 0)
		return Contain;
	if (strcmp(css_string_property, "contain-intrinsic-block-size") == 0)
		return ContainIntrinsicBlockSize;
	if (strcmp(css_string_property, "contain-intrinsic-height") == 0)
		return ContainIntrinsicHeight;
	if (strcmp(css_string_property, "contain-intrinsic-inline-size") == 0)
		return ContainIntrinsicInlineSize;
	if (strcmp(css_string_property, "contain-intrinsic-size") == 0)
		return ContainIntrinsicSize;
	if (strcmp(css_string_property, "contain-intrinsic-width") == 0)
		return ContainIntrinsicWidth;
	if (strcmp(css_string_property, "container") == 0)
		return Container;
	if (strcmp(css_string_property, "container-name") == 0)
		return ContainerName;
	if (strcmp(css_string_property, "container-type") == 0)
		return ContainerType;
	if (strcmp(css_string_property, "content") == 0)
		return Content;
	if (strcmp(css_string_property, "content-visibility") == 0)
		return ContentVisibility;
	if (strcmp(css_string_property, "continue") == 0)
		return Continue;
	if (strcmp(css_string_property, "counter-increment") == 0)
		return CounterIncrement;
	if (strcmp(css_string_property, "counter-reset") == 0)
		return CounterReset;
	if (strcmp(css_string_property, "counter-set") == 0)
		return CounterSet;
	if (strcmp(css_string_property, "cue") == 0)
		return Cue;
	if (strcmp(css_string_property, "cue-after") == 0)
		return CueAfter;
	if (strcmp(css_string_property, "cue-before") == 0)
		return CueBefore;
	if (strcmp(css_string_property, "cursor") == 0)
		return Cursor;
	if (strcmp(css_string_property, "direction") == 0)
		return Direction;
	if (strcmp(css_string_property, "display") == 0)
		return Display;
	if (strcmp(css_string_property, "dominant-baseline") == 0)
		return DominantBaseline;
	if (strcmp(css_string_property, "elevation") == 0)
		return Elevation;
	if (strcmp(css_string_property, "empty-cells") == 0)
		return EmptyCells;
	if (strcmp(css_string_property, "fill") == 0)
		return Fill;
	if (strcmp(css_string_property, "fill-break") == 0)
		return FillBreak;
	if (strcmp(css_string_property, "fill-color") == 0)
		return FillColor;
	if (strcmp(css_string_property, "fill-image") == 0)
		return FillImage;
	if (strcmp(css_string_property, "fill-opacity") == 0)
		return FillOpacity;
	if (strcmp(css_string_property, "fill-origin") == 0)
		return FillOrigin;
	if (strcmp(css_string_property, "fill-position") == 0)
		return FillPosition;
	if (strcmp(css_string_property, "fill-repeat") == 0)
		return FillRepeat;
	if (strcmp(css_string_property, "fill-rule") == 0)
		return FillRule;
	if (strcmp(css_string_property, "fill-size") == 0)
		return FillSize;
	if (strcmp(css_string_property, "filter") == 0)
		return Filter;
	if (strcmp(css_string_property, "flex") == 0)
		return Flex;
	if (strcmp(css_string_property, "flex-basis") == 0)
		return FlexBasis;
	if (strcmp(css_string_property, "flex-direction") == 0)
		return FlexDirection;
	if (strcmp(css_string_property, "flex-flow") == 0)
		return FlexFlow;
	if (strcmp(css_string_property, "flex-grow") == 0)
		return FlexGrow;
	if (strcmp(css_string_property, "flex-shrink") == 0)
		return FlexShrink;
	if (strcmp(css_string_property, "flex-wrap") == 0)
		return FlexWrap;
	if (strcmp(css_string_property, "float") == 0)
		return Float;
	if (strcmp(css_string_property, "float-defer") == 0)
		return FloatDefer;
	if (strcmp(css_string_property, "float-offset") == 0)
		return FloatOffset;
	if (strcmp(css_string_property, "float-reference") == 0)
		return FloatReference;
	if (strcmp(css_string_property, "flood-color") == 0)
		return FloodColor;
	if (strcmp(css_string_property, "flood-opacity") == 0)
		return FloodOpacity;
	if (strcmp(css_string_property, "flow") == 0)
		return Flow;
	if (strcmp(css_string_property, "flow-from") == 0)
		return FlowFrom;
	if (strcmp(css_string_property, "flow-into") == 0)
		return FlowInto;
	if (strcmp(css_string_property, "font") == 0)
		return Font;
	if (strcmp(css_string_property, "font-family") == 0)
		return FontFamily;
	if (strcmp(css_string_property, "font-feature-settings") == 0)
		return FontFeatureSettings;
	if (strcmp(css_string_property, "font-kerning") == 0)
		return FontKerning;
	if (strcmp(css_string_property, "font-language-override") == 0)
		return FontLanguageOverride;
	if (strcmp(css_string_property, "font-optical-sizing") == 0)
		return FontOpticalSizing;
	if (strcmp(css_string_property, "font-palette") == 0)
		return FontPalette;
	if (strcmp(css_string_property, "font-size") == 0)
		return FontSize;
	if (strcmp(css_string_property, "font-size-adjust") == 0)
		return FontSizeAdjust;
	if (strcmp(css_string_property, "font-stretch") == 0)
		return FontStretch;
	if (strcmp(css_string_property, "font-style") == 0)
		return FontStyle;
	if (strcmp(css_string_property, "font-synthesis") == 0)
		return FontSynthesis;
	if (strcmp(css_string_property, "font-synthesis-small-caps") == 0)
		return FontSynthesisSmallCaps;
	if (strcmp(css_string_property, "font-synthesis-style") == 0)
		return FontSynthesisStyle;
	if (strcmp(css_string_property, "font-synthesis-weight") == 0)
		return FontSynthesisWeight;
	if (strcmp(css_string_property, "font-variant") == 0)
		return FontVariant;
	if (strcmp(css_string_property, "font-variant-alternates") == 0)
		return FontVariantAlternates;
	if (strcmp(css_string_property, "font-variant-caps") == 0)
		return FontVariantCaps;
	if (strcmp(css_string_property, "font-variant-east-asian") == 0)
		return FontVariantEastAsian;
	if (strcmp(css_string_property, "font-variant-emoji") == 0)
		return FontVariantEmoji;
	if (strcmp(css_string_property, "font-variant-ligatures") == 0)
		return FontVariantLigatures;
	if (strcmp(css_string_property, "font-variant-numeric") == 0)
		return FontVariantNumeric;
	if (strcmp(css_string_property, "font-variant-position") == 0)
		return FontVariantPosition;
	if (strcmp(css_string_property, "font-variation-settings") == 0)
		return FontVariationSettings;
	if (strcmp(css_string_property, "font-weight") == 0)
		return FontWeight;
	if (strcmp(css_string_property, "footnote-display") == 0)
		return FootnoteDisplay;
	if (strcmp(css_string_property, "footnote-policy") == 0)
		return FootnotePolicy;
	if (strcmp(css_string_property, "forced-color-adjust") == 0)
		return ForcedColorAdjust;
	if (strcmp(css_string_property, "gap") == 0)
		return Gap;
	if (strcmp(css_string_property, "glyph-orientation-vertical") == 0)
		return GlyphOrientationVertical;
	if (strcmp(css_string_property, "grid") == 0)
		return Grid;
	if (strcmp(css_string_property, "grid-area") == 0)
		return GridArea;
	if (strcmp(css_string_property, "grid-auto-columns") == 0)
		return GridAutoColumns;
	if (strcmp(css_string_property, "grid-auto-flow") == 0)
		return GridAutoFlow;
	if (strcmp(css_string_property, "grid-auto-rows") == 0)
		return GridAutoRows;
	if (strcmp(css_string_property, "grid-column") == 0)
		return GridColumn;
	if (strcmp(css_string_property, "grid-column-end") == 0)
		return GridColumnEnd;
	if (strcmp(css_string_property, "grid-column-start") == 0)
		return GridColumnStart;
	if (strcmp(css_string_property, "grid-row") == 0)
		return GridRow;
	if (strcmp(css_string_property, "grid-row-end") == 0)
		return GridRowEnd;
	if (strcmp(css_string_property, "grid-row-start") == 0)
		return GridRowStart;
	if (strcmp(css_string_property, "grid-template") == 0)
		return GridTemplate;
	if (strcmp(css_string_property, "grid-template-areas") == 0)
		return GridTemplateAreas;
	if (strcmp(css_string_property, "grid-template-columns") == 0)
		return GridTemplateColumns;
	if (strcmp(css_string_property, "grid-template-rows") == 0)
		return GridTemplateRows;
	if (strcmp(css_string_property, "hanging-punctuation") == 0)
		return HangingPunctuation;
	if (strcmp(css_string_property, "height") == 0)
		return Height;
	if (strcmp(css_string_property, "hyphenate-character") == 0)
		return HyphenateCharacter;
	if (strcmp(css_string_property, "hyphenate-limit-chars") == 0)
		return HyphenateLimitChars;
	if (strcmp(css_string_property, "hyphenate-limit-last") == 0)
		return HyphenateLimitLast;
	if (strcmp(css_string_property, "hyphenate-limit-lines") == 0)
		return HyphenateLimitLines;
	if (strcmp(css_string_property, "hyphenate-limit-zone") == 0)
		return HyphenateLimitZone;
	if (strcmp(css_string_property, "hyphens") == 0)
		return Hyphens;
	if (strcmp(css_string_property, "image-orientation") == 0)
		return ImageOrientation;
	if (strcmp(css_string_property, "image-rendering") == 0)
		return ImageRendering;
	if (strcmp(css_string_property, "image-resolution") == 0)
		return ImageResolution;
	if (strcmp(css_string_property, "initial-letter") == 0)
		return InitialLetter;
	if (strcmp(css_string_property, "initial-letter-align") == 0)
		return InitialLetterAlign;
	if (strcmp(css_string_property, "initial-letter-wrap") == 0)
		return InitialLetterWrap;
	if (strcmp(css_string_property, "inline-size") == 0)
		return InlineSize;
	if (strcmp(css_string_property, "inline-sizing") == 0)
		return InlineSizing;
	if (strcmp(css_string_property, "input-security") == 0)
		return InputSecurity;
	if (strcmp(css_string_property, "inset") == 0)
		return Inset;
	if (strcmp(css_string_property, "inset-block") == 0)
		return InsetBlock;
	if (strcmp(css_string_property, "inset-block-end") == 0)
		return InsetBlockEnd;
	if (strcmp(css_string_property, "inset-block-start") == 0)
		return InsetBlockStart;
	if (strcmp(css_string_property, "inset-inline") == 0)
		return InsetInline;
	if (strcmp(css_string_property, "inset-inline-end") == 0)
		return InsetInlineEnd;
	if (strcmp(css_string_property, "inset-inline-start") == 0)
		return InsetInlineStart;
	if (strcmp(css_string_property, "isolation") == 0)
		return Isolation;
	if (strcmp(css_string_property, "justify-content") == 0)
		return JustifyContent;
	if (strcmp(css_string_property, "justify-items") == 0)
		return JustifyItems;
	if (strcmp(css_string_property, "justify-self") == 0)
		return JustifySelf;
	if (strcmp(css_string_property, "left") == 0)
		return Left;
	if (strcmp(css_string_property, "letter-spacing") == 0)
		return LetterSpacing;
	if (strcmp(css_string_property, "lighting-color") == 0)
		return LightingColor;
	if (strcmp(css_string_property, "line-break") == 0)
		return LineBreak;
	if (strcmp(css_string_property, "line-clamp") == 0)
		return LineClamp;
	if (strcmp(css_string_property, "line-grid") == 0)
		return LineGrid;
	if (strcmp(css_string_property, "line-height") == 0)
		return LineHeight;
	if (strcmp(css_string_property, "line-height-step") == 0)
		return LineHeightStep;
	if (strcmp(css_string_property, "line-padding") == 0)
		return LinePadding;
	if (strcmp(css_string_property, "line-snap") == 0)
		return LineSnap;
	if (strcmp(css_string_property, "list-style") == 0)
		return ListStyle;
	if (strcmp(css_string_property, "list-style-image") == 0)
		return ListStyleImage;
	if (strcmp(css_string_property, "list-style-position") == 0)
		return ListStylePosition;
	if (strcmp(css_string_property, "list-style-type") == 0)
		return ListStyleType;
	if (strcmp(css_string_property, "margin") == 0)
		return Margin;
	if (strcmp(css_string_property, "margin-block") == 0)
		return MarginBlock;
	if (strcmp(css_string_property, "margin-block-end") == 0)
		return MarginBlockEnd;
	if (strcmp(css_string_property, "margin-block-start") == 0)
		return MarginBlockStart;
	if (strcmp(css_string_property, "margin-bottom") == 0)
		return MarginBottom;
	if (strcmp(css_string_property, "margin-break") == 0)
		return MarginBreak;
	if (strcmp(css_string_property, "margin-inline") == 0)
		return MarginInline;
	if (strcmp(css_string_property, "margin-inline-end") == 0)
		return MarginInlineEnd;
	if (strcmp(css_string_property, "margin-inline-start") == 0)
		return MarginInlineStart;
	if (strcmp(css_string_property, "margin-left") == 0)
		return MarginLeft;
	if (strcmp(css_string_property, "margin-right") == 0)
		return MarginRight;
	if (strcmp(css_string_property, "margin-top") == 0)
		return MarginTop;
	if (strcmp(css_string_property, "margin-trim") == 0)
		return MarginTrim;
	if (strcmp(css_string_property, "marker") == 0)
		return Marker;
	if (strcmp(css_string_property, "marker-end") == 0)
		return MarkerEnd;
	if (strcmp(css_string_property, "marker-knockout-left") == 0)
		return MarkerKnockoutLeft;
	if (strcmp(css_string_property, "marker-knockout-right") == 0)
		return MarkerKnockoutRight;
	if (strcmp(css_string_property, "marker-mid") == 0)
		return MarkerMid;
	if (strcmp(css_string_property, "marker-pattern") == 0)
		return MarkerPattern;
	if (strcmp(css_string_property, "marker-segment") == 0)
		return MarkerSegment;
	if (strcmp(css_string_property, "marker-side") == 0)
		return MarkerSide;
	if (strcmp(css_string_property, "marker-start") == 0)
		return MarkerStart;
	if (strcmp(css_string_property, "mask") == 0)
		return Mask;
	if (strcmp(css_string_property, "mask-border") == 0)
		return MaskBorder;
	if (strcmp(css_string_property, "mask-border-mode") == 0)
		return MaskBorderMode;
	if (strcmp(css_string_property, "mask-border-outset") == 0)
		return MaskBorderOutset;
	if (strcmp(css_string_property, "mask-border-repeat") == 0)
		return MaskBorderRepeat;
	if (strcmp(css_string_property, "mask-border-slice") == 0)
		return MaskBorderSlice;
	if (strcmp(css_string_property, "mask-border-source") == 0)
		return MaskBorderSource;
	if (strcmp(css_string_property, "mask-border-width") == 0)
		return MaskBorderWidth;
	if (strcmp(css_string_property, "mask-clip") == 0)
		return MaskClip;
	if (strcmp(css_string_property, "mask-composite") == 0)
		return MaskComposite;
	if (strcmp(css_string_property, "mask-image") == 0)
		return MaskImage;
	if (strcmp(css_string_property, "mask-mode") == 0)
		return MaskMode;
	if (strcmp(css_string_property, "mask-origin") == 0)
		return MaskOrigin;
	if (strcmp(css_string_property, "mask-position") == 0)
		return MaskPosition;
	if (strcmp(css_string_property, "mask-repeat") == 0)
		return MaskRepeat;
	if (strcmp(css_string_property, "mask-size") == 0)
		return MaskSize;
	if (strcmp(css_string_property, "mask-type") == 0)
		return MaskType;
	if (strcmp(css_string_property, "max-block-size") == 0)
		return MaxBlockSize;
	if (strcmp(css_string_property, "max-height") == 0)
		return MaxHeight;
	if (strcmp(css_string_property, "max-inline-size") == 0)
		return MaxInlineSize;
	if (strcmp(css_string_property, "max-lines") == 0)
		return MaxLines;
	if (strcmp(css_string_property, "max-width") == 0)
		return MaxWidth;
	if (strcmp(css_string_property, "min-block-size") == 0)
		return MinBlockSize;
	if (strcmp(css_string_property, "min-height") == 0)
		return MinHeight;
	if (strcmp(css_string_property, "min-inline-size") == 0)
		return MinInlineSize;
	if (strcmp(css_string_property, "min-intrinsic-sizing") == 0)
		return MinIntrinsicSizing;
	if (strcmp(css_string_property, "min-width") == 0)
		return MinWidth;
	if (strcmp(css_string_property, "mix-blend-mode") == 0)
		return MixBlendMode;
	if (strcmp(css_string_property, "nav-down") == 0)
		return NavDown;
	if (strcmp(css_string_property, "nav-left") == 0)
		return NavLeft;
	if (strcmp(css_string_property, "nav-right") == 0)
		return NavRight;
	if (strcmp(css_string_property, "nav-up") == 0)
		return NavUp;
	if (strcmp(css_string_property, "object-fit") == 0)
		return ObjectFit;
	if (strcmp(css_string_property, "object-position") == 0)
		return ObjectPosition;
	if (strcmp(css_string_property, "offset") == 0)
		return Offset;
	if (strcmp(css_string_property, "offset-anchor") == 0)
		return OffsetAnchor;
	if (strcmp(css_string_property, "offset-distance") == 0)
		return OffsetDistance;
	if (strcmp(css_string_property, "offset-path") == 0)
		return OffsetPath;
	if (strcmp(css_string_property, "offset-position") == 0)
		return OffsetPosition;
	if (strcmp(css_string_property, "offset-rotate") == 0)
		return OffsetRotate;
	if (strcmp(css_string_property, "opacity") == 0)
		return Opacity;
	if (strcmp(css_string_property, "order") == 0)
		return Order;
	if (strcmp(css_string_property, "orphans") == 0)
		return Orphans;
	if (strcmp(css_string_property, "outline") == 0)
		return Outline;
	if (strcmp(css_string_property, "outline-color") == 0)
		return OutlineColor;
	if (strcmp(css_string_property, "outline-offset") == 0)
		return OutlineOffset;
	if (strcmp(css_string_property, "outline-style") == 0)
		return OutlineStyle;
	if (strcmp(css_string_property, "outline-width") == 0)
		return OutlineWidth;
	if (strcmp(css_string_property, "overflow") == 0)
		return Overflow;
	if (strcmp(css_string_property, "overflow-anchor") == 0)
		return OverflowAnchor;
	if (strcmp(css_string_property, "overflow-block") == 0)
		return OverflowBlock;
	if (strcmp(css_string_property, "overflow-clip-margin") == 0)
		return OverflowClipMargin;
	if (strcmp(css_string_property, "overflow-clip-margin-block") == 0)
		return OverflowClipMarginBlock;
	if (strcmp(css_string_property, "overflow-clip-margin-block-end") == 0)
		return OverflowClipMarginBlockEnd;
	if (strcmp(css_string_property, "overflow-clip-margin-block-start") == 0)
		return OverflowClipMarginBlockStart;
	if (strcmp(css_string_property, "overflow-clip-margin-bottom") == 0)
		return OverflowClipMarginBottom;
	if (strcmp(css_string_property, "overflow-clip-margin-inline") == 0)
		return OverflowClipMarginInline;
	if (strcmp(css_string_property, "overflow-clip-margin-inline-end") == 0)
		return OverflowClipMarginInlineEnd;
	if (strcmp(css_string_property, "overflow-clip-margin-inline-start") == 0)
		return OverflowClipMarginInlineStart;
	if (strcmp(css_string_property, "overflow-clip-margin-left") == 0)
		return OverflowClipMarginLeft;
	if (strcmp(css_string_property, "overflow-clip-margin-right") == 0)
		return OverflowClipMarginRight;
	if (strcmp(css_string_property, "overflow-clip-margin-top") == 0)
		return OverflowClipMarginTop;
	if (strcmp(css_string_property, "overflow-inline") == 0)
		return OverflowInline;
	if (strcmp(css_string_property, "overflow-wrap") == 0)
		return OverflowWrap;
	if (strcmp(css_string_property, "overflow-x") == 0)
		return OverflowX;
	if (strcmp(css_string_property, "overflow-y") == 0)
		return OverflowY;
	if (strcmp(css_string_property, "overscroll-behavior") == 0)
		return OverscrollBehavior;
	if (strcmp(css_string_property, "overscroll-behavior-block") == 0)
		return OverscrollBehaviorBlock;
	if (strcmp(css_string_property, "overscroll-behavior-inline") == 0)
		return OverscrollBehaviorInline;
	if (strcmp(css_string_property, "overscroll-behavior-x") == 0)
		return OverscrollBehaviorX;
	if (strcmp(css_string_property, "overscroll-behavior-y") == 0)
		return OverscrollBehaviorY;
	if (strcmp(css_string_property, "padding") == 0)
		return Padding;
	if (strcmp(css_string_property, "padding-block") == 0)
		return PaddingBlock;
	if (strcmp(css_string_property, "padding-block-end") == 0)
		return PaddingBlockEnd;
	if (strcmp(css_string_property, "padding-block-start") == 0)
		return PaddingBlockStart;
	if (strcmp(css_string_property, "padding-bottom") == 0)
		return PaddingBottom;
	if (strcmp(css_string_property, "padding-inline") == 0)
		return PaddingInline;
	if (strcmp(css_string_property, "padding-inline-end") == 0)
		return PaddingInlineEnd;
	if (strcmp(css_string_property, "padding-inline-start") == 0)
		return PaddingInlineStart;
	if (strcmp(css_string_property, "padding-left") == 0)
		return PaddingLeft;
	if (strcmp(css_string_property, "padding-right") == 0)
		return PaddingRight;
	if (strcmp(css_string_property, "padding-top") == 0)
		return PaddingTop;
	if (strcmp(css_string_property, "page") == 0)
		return Page;
	if (strcmp(css_string_property, "page-break-after") == 0)
		return PageBreakAfter;
	if (strcmp(css_string_property, "page-break-before") == 0)
		return PageBreakBefore;
	if (strcmp(css_string_property, "page-break-inside") == 0)
		return PageBreakInside;
	if (strcmp(css_string_property, "pause") == 0)
		return Pause;
	if (strcmp(css_string_property, "pause-after") == 0)
		return PauseAfter;
	if (strcmp(css_string_property, "pause-before") == 0)
		return PauseBefore;
	if (strcmp(css_string_property, "perspective") == 0)
		return Perspective;
	if (strcmp(css_string_property, "perspective-origin") == 0)
		return PerspectiveOrigin;
	if (strcmp(css_string_property, "pitch") == 0)
		return Pitch;
	if (strcmp(css_string_property, "pitch-range") == 0)
		return PitchRange;
	if (strcmp(css_string_property, "place-content") == 0)
		return PlaceContent;
	if (strcmp(css_string_property, "place-items") == 0)
		return PlaceItems;
	if (strcmp(css_string_property, "place-self") == 0)
		return PlaceSelf;
	if (strcmp(css_string_property, "play-during") == 0)
		return PlayDuring;
	if (strcmp(css_string_property, "pointer-events") == 0)
		return PointerEvents;
	if (strcmp(css_string_property, "position") == 0)
		return Position;
	if (strcmp(css_string_property, "print-color-adjust") == 0)
		return PrintColorAdjust;
	if (strcmp(css_string_property, "property-name") == 0)
		return PropertyName;
	if (strcmp(css_string_property, "quotes") == 0)
		return Quotes;
	if (strcmp(css_string_property, "region-fragment") == 0)
		return RegionFragment;
	if (strcmp(css_string_property, "resize") == 0)
		return Resize;
	if (strcmp(css_string_property, "rest") == 0)
		return Rest;
	if (strcmp(css_string_property, "rest-after") == 0)
		return RestAfter;
	if (strcmp(css_string_property, "rest-before") == 0)
		return RestBefore;
	if (strcmp(css_string_property, "richness") == 0)
		return Richness;
	if (strcmp(css_string_property, "right") == 0)
		return Right;
	if (strcmp(css_string_property, "rotate") == 0)
		return Rotate;
	if (strcmp(css_string_property, "row-gap") == 0)
		return RowGap;
	if (strcmp(css_string_property, "ruby-align") == 0)
		return RubyAlign;
	if (strcmp(css_string_property, "ruby-merge") == 0)
		return RubyMerge;
	if (strcmp(css_string_property, "ruby-overhang") == 0)
		return RubyOverhang;
	if (strcmp(css_string_property, "ruby-position") == 0)
		return RubyPosition;
	if (strcmp(css_string_property, "running") == 0)
		return Running;
	if (strcmp(css_string_property, "scale") == 0)
		return Scale;
	if (strcmp(css_string_property, "scroll-behavior") == 0)
		return ScrollBehavior;
	if (strcmp(css_string_property, "scroll-margin") == 0)
		return ScrollMargin;
	if (strcmp(css_string_property, "scroll-margin-block") == 0)
		return ScrollMarginBlock;
	if (strcmp(css_string_property, "scroll-margin-block-end") == 0)
		return ScrollMarginBlockEnd;
	if (strcmp(css_string_property, "scroll-margin-block-start") == 0)
		return ScrollMarginBlockStart;
	if (strcmp(css_string_property, "scroll-margin-bottom") == 0)
		return ScrollMarginBottom;
	if (strcmp(css_string_property, "scroll-margin-inline") == 0)
		return ScrollMarginInline;
	if (strcmp(css_string_property, "scroll-margin-inline-end") == 0)
		return ScrollMarginInlineEnd;
	if (strcmp(css_string_property, "scroll-margin-inline-start") == 0)
		return ScrollMarginInlineStart;
	if (strcmp(css_string_property, "scroll-margin-left") == 0)
		return ScrollMarginLeft;
	if (strcmp(css_string_property, "scroll-margin-right") == 0)
		return ScrollMarginRight;
	if (strcmp(css_string_property, "scroll-margin-top") == 0)
		return ScrollMarginTop;
	if (strcmp(css_string_property, "scroll-padding") == 0)
		return ScrollPadding;
	if (strcmp(css_string_property, "scroll-padding-block") == 0)
		return ScrollPaddingBlock;
	if (strcmp(css_string_property, "scroll-padding-block-end") == 0)
		return ScrollPaddingBlockEnd;
	if (strcmp(css_string_property, "scroll-padding-block-start") == 0)
		return ScrollPaddingBlockStart;
	if (strcmp(css_string_property, "scroll-padding-bottom") == 0)
		return ScrollPaddingBottom;
	if (strcmp(css_string_property, "scroll-padding-inline") == 0)
		return ScrollPaddingInline;
	if (strcmp(css_string_property, "scroll-padding-inline-end") == 0)
		return ScrollPaddingInlineEnd;
	if (strcmp(css_string_property, "scroll-padding-inline-start") == 0)
		return ScrollPaddingInlineStart;
	if (strcmp(css_string_property, "scroll-padding-left") == 0)
		return ScrollPaddingLeft;
	if (strcmp(css_string_property, "scroll-padding-right") == 0)
		return ScrollPaddingRight;
	if (strcmp(css_string_property, "scroll-padding-top") == 0)
		return ScrollPaddingTop;
	if (strcmp(css_string_property, "scroll-snap-align") == 0)
		return ScrollSnapAlign;
	if (strcmp(css_string_property, "scroll-snap-stop") == 0)
		return ScrollSnapStop;
	if (strcmp(css_string_property, "scroll-snap-type") == 0)
		return ScrollSnapType;
	if (strcmp(css_string_property, "scroll-timeline") == 0)
		return ScrollTimeline;
	if (strcmp(css_string_property, "scroll-timeline-attachment") == 0)
		return ScrollTimelineAttachment;
	if (strcmp(css_string_property, "scroll-timeline-axis") == 0)
		return ScrollTimelineAxis;
	if (strcmp(css_string_property, "scroll-timeline-name") == 0)
		return ScrollTimelineName;
	if (strcmp(css_string_property, "scrollbar-color") == 0)
		return ScrollbarColor;
	if (strcmp(css_string_property, "scrollbar-gutter") == 0)
		return ScrollbarGutter;
	if (strcmp(css_string_property, "scrollbar-width") == 0)
		return ScrollbarWidth;
	if (strcmp(css_string_property, "shape-image-threshold") == 0)
		return ShapeImageThreshold;
	if (strcmp(css_string_property, "shape-inside") == 0)
		return ShapeInside;
	if (strcmp(css_string_property, "shape-margin") == 0)
		return ShapeMargin;
	if (strcmp(css_string_property, "shape-outside") == 0)
		return ShapeOutside;
	if (strcmp(css_string_property, "spatial-navigation-action") == 0)
		return SpatialNavigationAction;
	if (strcmp(css_string_property, "spatial-navigation-contain") == 0)
		return SpatialNavigationContain;
	if (strcmp(css_string_property, "spatial-navigation-function") == 0)
		return SpatialNavigationFunction;
	if (strcmp(css_string_property, "speak") == 0)
		return Speak;
	if (strcmp(css_string_property, "speak-as") == 0)
		return SpeakAs;
	if (strcmp(css_string_property, "speak-header") == 0)
		return SpeakHeader;
	if (strcmp(css_string_property, "speak-numeral") == 0)
		return SpeakNumeral;
	if (strcmp(css_string_property, "speak-punctuation") == 0)
		return SpeakPunctuation;
	if (strcmp(css_string_property, "speech-rate") == 0)
		return SpeechRate;
	if (strcmp(css_string_property, "stress") == 0)
		return Stress;
	if (strcmp(css_string_property, "string-set") == 0)
		return StringSet;
	if (strcmp(css_string_property, "stroke") == 0)
		return Stroke;
	if (strcmp(css_string_property, "stroke-align") == 0)
		return StrokeAlign;
	if (strcmp(css_string_property, "stroke-alignment") == 0)
		return StrokeAlignment;
	if (strcmp(css_string_property, "stroke-break") == 0)
		return StrokeBreak;
	if (strcmp(css_string_property, "stroke-color") == 0)
		return StrokeColor;
	if (strcmp(css_string_property, "stroke-dash-corner") == 0)
		return StrokeDashCorner;
	if (strcmp(css_string_property, "stroke-dash-justify") == 0)
		return StrokeDashJustify;
	if (strcmp(css_string_property, "stroke-dashadjust") == 0)
		return StrokeDashadjust;
	if (strcmp(css_string_property, "stroke-dasharray") == 0)
		return StrokeDasharray;
	if (strcmp(css_string_property, "stroke-dashcorner") == 0)
		return StrokeDashcorner;
	if (strcmp(css_string_property, "stroke-dashoffset") == 0)
		return StrokeDashoffset;
	if (strcmp(css_string_property, "stroke-image") == 0)
		return StrokeImage;
	if (strcmp(css_string_property, "stroke-linecap") == 0)
		return StrokeLinecap;
	if (strcmp(css_string_property, "stroke-linejoin") == 0)
		return StrokeLinejoin;
	if (strcmp(css_string_property, "stroke-miterlimit") == 0)
		return StrokeMiterlimit;
	if (strcmp(css_string_property, "stroke-opacity") == 0)
		return StrokeOpacity;
	if (strcmp(css_string_property, "stroke-origin") == 0)
		return StrokeOrigin;
	if (strcmp(css_string_property, "stroke-position") == 0)
		return StrokePosition;
	if (strcmp(css_string_property, "stroke-repeat") == 0)
		return StrokeRepeat;
	if (strcmp(css_string_property, "stroke-size") == 0)
		return StrokeSize;
	if (strcmp(css_string_property, "stroke-width") == 0)
		return StrokeWidth;
	if (strcmp(css_string_property, "tab-size") == 0)
		return TabSize;
	if (strcmp(css_string_property, "table-layout") == 0)
		return TableLayout;
	if (strcmp(css_string_property, "text-align") == 0)
		return TextAlign;
	if (strcmp(css_string_property, "text-align-all") == 0)
		return TextAlignAll;
	if (strcmp(css_string_property, "text-align-last") == 0)
		return TextAlignLast;
	if (strcmp(css_string_property, "text-autospace") == 0)
		return TextAutospace;
	if (strcmp(css_string_property, "text-box-edge") == 0)
		return TextBoxEdge;
	if (strcmp(css_string_property, "text-box-trim") == 0)
		return TextBoxTrim;
	if (strcmp(css_string_property, "text-combine-upright") == 0)
		return TextCombineUpright;
	if (strcmp(css_string_property, "text-decoration") == 0)
		return TextDecoration;
	if (strcmp(css_string_property, "text-decoration-color") == 0)
		return TextDecorationColor;
	if (strcmp(css_string_property, "text-decoration-line") == 0)
		return TextDecorationLine;
	if (strcmp(css_string_property, "text-decoration-skip") == 0)
		return TextDecorationSkip;
	if (strcmp(css_string_property, "text-decoration-skip-box") == 0)
		return TextDecorationSkipBox;
	if (strcmp(css_string_property, "text-decoration-skip-ink") == 0)
		return TextDecorationSkipInk;
	if (strcmp(css_string_property, "text-decoration-skip-inset") == 0)
		return TextDecorationSkipInset;
	if (strcmp(css_string_property, "text-decoration-skip-self") == 0)
		return TextDecorationSkipSelf;
	if (strcmp(css_string_property, "text-decoration-skip-spaces") == 0)
		return TextDecorationSkipSpaces;
	if (strcmp(css_string_property, "text-decoration-style") == 0)
		return TextDecorationStyle;
	if (strcmp(css_string_property, "text-decoration-thickness") == 0)
		return TextDecorationThickness;
	if (strcmp(css_string_property, "text-decoration-trim") == 0)
		return TextDecorationTrim;
	if (strcmp(css_string_property, "text-emphasis") == 0)
		return TextEmphasis;
	if (strcmp(css_string_property, "text-emphasis-color") == 0)
		return TextEmphasisColor;
	if (strcmp(css_string_property, "text-emphasis-position") == 0)
		return TextEmphasisPosition;
	if (strcmp(css_string_property, "text-emphasis-skip") == 0)
		return TextEmphasisSkip;
	if (strcmp(css_string_property, "text-emphasis-style") == 0)
		return TextEmphasisStyle;
	if (strcmp(css_string_property, "text-group-align") == 0)
		return TextGroupAlign;
	if (strcmp(css_string_property, "text-indent") == 0)
		return TextIndent;
	if (strcmp(css_string_property, "text-justify") == 0)
		return TextJustify;
	if (strcmp(css_string_property, "text-orientation") == 0)
		return TextOrientation;
	if (strcmp(css_string_property, "text-overflow") == 0)
		return TextOverflow;
	if (strcmp(css_string_property, "text-shadow") == 0)
		return TextShadow;
	if (strcmp(css_string_property, "text-spacing") == 0)
		return TextSpacing;
	if (strcmp(css_string_property, "text-spacing-trim") == 0)
		return TextSpacingTrim;
	if (strcmp(css_string_property, "text-transform") == 0)
		return TextTransform;
	if (strcmp(css_string_property, "text-underline-offset") == 0)
		return TextUnderlineOffset;
	if (strcmp(css_string_property, "text-underline-position") == 0)
		return TextUnderlinePosition;
	if (strcmp(css_string_property, "text-wrap") == 0)
		return TextWrap;
	if (strcmp(css_string_property, "top") == 0)
		return Top;
	if (strcmp(css_string_property, "transform") == 0)
		return Transform;
	if (strcmp(css_string_property, "transform-box") == 0)
		return TransformBox;
	if (strcmp(css_string_property, "transform-origin") == 0)
		return TransformOrigin;
	if (strcmp(css_string_property, "transform-style") == 0)
		return TransformStyle;
	if (strcmp(css_string_property, "transition") == 0)
		return Transition;
	if (strcmp(css_string_property, "transition-delay") == 0)
		return TransitionDelay;
	if (strcmp(css_string_property, "transition-duration") == 0)
		return TransitionDuration;
	if (strcmp(css_string_property, "transition-property") == 0)
		return TransitionProperty;
	if (strcmp(css_string_property, "transition-timing-function") == 0)
		return TransitionTimingFunction;
	if (strcmp(css_string_property, "translate") == 0)
		return Translate;
	if (strcmp(css_string_property, "unicode-bidi") == 0)
		return UnicodeBidi;
	if (strcmp(css_string_property, "user-select") == 0)
		return UserSelect;
	if (strcmp(css_string_property, "vertical-align") == 0)
		return VerticalAlign;
	if (strcmp(css_string_property, "view-timeline") == 0)
		return ViewTimeline;
	if (strcmp(css_string_property, "view-timeline-attachment") == 0)
		return ViewTimelineAttachment;
	if (strcmp(css_string_property, "view-timeline-axis") == 0)
		return ViewTimelineAxis;
	if (strcmp(css_string_property, "view-timeline-inset") == 0)
		return ViewTimelineInset;
	if (strcmp(css_string_property, "view-timeline-name") == 0)
		return ViewTimelineName;
	if (strcmp(css_string_property, "view-transition-name") == 0)
		return ViewTransitionName;
	if (strcmp(css_string_property, "visibility") == 0)
		return Visibility;
	if (strcmp(css_string_property, "voice-balance") == 0)
		return VoiceBalance;
	if (strcmp(css_string_property, "voice-duration") == 0)
		return VoiceDuration;
	if (strcmp(css_string_property, "voice-family") == 0)
		return VoiceFamily;
	if (strcmp(css_string_property, "voice-pitch") == 0)
		return VoicePitch;
	if (strcmp(css_string_property, "voice-range") == 0)
		return VoiceRange;
	if (strcmp(css_string_property, "voice-rate") == 0)
		return VoiceRate;
	if (strcmp(css_string_property, "voice-stress") == 0)
		return VoiceStress;
	if (strcmp(css_string_property, "voice-volume") == 0)
		return VoiceVolume;
	if (strcmp(css_string_property, "volume") == 0)
		return Volume;
	if (strcmp(css_string_property, "white-space") == 0)
		return WhiteSpace;
	if (strcmp(css_string_property, "white-space-collapse") == 0)
		return WhiteSpaceCollapse;
	if (strcmp(css_string_property, "white-space-trim") == 0)
		return WhiteSpaceTrim;
	if (strcmp(css_string_property, "widows") == 0)
		return Widows;
	if (strcmp(css_string_property, "width") == 0)
		return Width;
	if (strcmp(css_string_property, "will-change") == 0)
		return WillChange;
	if (strcmp(css_string_property, "word-boundary-detection") == 0)
		return WordBoundaryDetection;
	if (strcmp(css_string_property, "word-boundary-expansion") == 0)
		return WordBoundaryExpansion;
	if (strcmp(css_string_property, "word-break") == 0)
		return WordBreak;
	if (strcmp(css_string_property, "word-spacing") == 0)
		return WordSpacing;
	if (strcmp(css_string_property, "word-wrap") == 0)
		return WordWrap;
	if (strcmp(css_string_property, "wrap-after") == 0)
		return WrapAfter;
	if (strcmp(css_string_property, "wrap-before") == 0)
		return WrapBefore;
	if (strcmp(css_string_property, "wrap-flow") == 0)
		return WrapFlow;
	if (strcmp(css_string_property, "wrap-inside") == 0)
		return WrapInside;
	if (strcmp(css_string_property, "wrap-through") == 0)
		return WrapThrough;
	if (strcmp(css_string_property, "writing-mode") == 0)
		return WritingMode;
	if (strcmp(css_string_property, "z-index") == 0)
		return ZIndex;

    /* If our string isn't any of these we return
     * -1 as information that it's invalid style
     * rule name */
    return -1;
}